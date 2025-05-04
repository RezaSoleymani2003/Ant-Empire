#include "ant.h"
#include "pheromone.h"
#include <algorithm>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

using namespace std;
const int ANT_CNT = 250;
const int ANTS_PER_THREAD = 10;
const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 800;

mutex antsLock;
// mutex pheromonesLock;
atomic<bool> running(true);

vector<Ant> ants;
vector<Pheromone> pheremoneTrails;

void handleAnts(int start, int end) {
    sf::Clock clock;
    while(running) {
        float deltaTime = clock.restart().asSeconds();

        antsLock.lock();  // Single lock for the whole operation
        for(int i = start; i < end; i++) {
            if (ants[i].pheromoneCounter > 5) {
                pheremoneTrails.push_back(ants[i].createPheromone("Blue"));
                ants[i].pheromoneCounter = 0;
            } else {
                ants[i].pheromoneCounter++;
            }
            
            sf::Vector2f pos = ants[i].shape.getPosition();
            if (pos.x + ANT_SIZE*2 >= WINDOW_WIDTH || pos.x <= 0) {
                ants[i].velocity.x *= -1;
            }
            if (pos.y + ANT_SIZE*2 >= WINDOW_HEIGHT || pos.y <= 0) {
                ants[i].velocity.y *= -1;
            }
            ants[i].shape.move(ants[i].velocity);
        }
        antsLock.unlock();

        this_thread::sleep_for(chrono::milliseconds(1)); // Reduce CPU usage
    }
}

int main()
{
    ants = createAnts(ANT_CNT, vector<string> {"blue"});
    vector<thread> threads;
    int threadCount = ceil(float(ANT_CNT) / float(ANTS_PER_THREAD));
    // cout << float(ANT_CNT) / float(ANTS_PER_THREAD) << endl;
    cout << threadCount << endl;
    
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "SFML Sucks!");
    window.setFramerateLimit(30);

    bool createPheromone = true;
    int count = 0;
    
    for (size_t i = 0; i < threadCount; i++){
        int start = i * ANTS_PER_THREAD;
        int end = min(start + ANTS_PER_THREAD, ANT_CNT);
        threads.push_back(thread(handleAnts, start, end));
    }
    cout << endl << cos(SIGHT_ANGLE) <<endl;

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){   
            if (event->is<sf::Event::Closed>()){
                window.close();
                
            }
            
        }
        
        window.clear();
        antsLock.lock();
        for(Ant& ant : ants){
            window.draw(ant.shape);
            // ant.print();
        }
        // antsLock.unlock();
        
        // antsLock.lock();
        pheremoneTrails.erase(
            remove_if(pheremoneTrails.begin(), pheremoneTrails.end(),
            [](Pheromone& p) {
                p.decay(-0.01f);
                return p.intensity == 0;
            }),
            pheremoneTrails.end()
        );
        
        
        for (const Pheromone& pheromone : pheremoneTrails) {
            window.draw(pheromone.shape);
        }
        antsLock.unlock();
        
        // cout << pheremoneTrails.size() << endl;
        window.display();
    }

    running = false;
    for (thread& t : threads) {
        t.join();
    }
    
    ants.clear(); // clear all ants
    pheremoneTrails.clear(); // clear all pheromones
    threads.clear();
}