CXX = g++
CXXFLAGS = -Wall -g
TARGET = main
OBJS = main.o
all: $(TARGET)

# Link the target with object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp MyQueue.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(TARGET)
	