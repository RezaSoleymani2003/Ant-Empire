# Compile step (creates .o files)
%.o: %.cpp
	$(CXX) -c $< -o $@ $(INCLUDES)