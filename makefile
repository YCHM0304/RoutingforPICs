CC=g++
SOURCES=main.cpp Vertex_Pair.cpp Graph.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=b10932010
INCLUDES=*.h

./$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS)  $(OBJECTS) -o $@


$(SOURCES:%.o):$(SOURCES:%.cpp)  ${INCLUDES}
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf *.o ./$(EXECUTABLE)
