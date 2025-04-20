# Link step (creates final executable)
$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ $(LIBS)