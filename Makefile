CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pthread

TARGET = ProducerConsumer

SOURCES = \
    main.cpp \
    Producer.cpp \
    Consumer.cpp \
    ThreadSafeQueue.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)