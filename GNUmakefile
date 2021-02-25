CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic
VPATH = src:lib
OBJECTS = PPlot.o SVGPainter.o test.o main.o 

assignment4: $(OBJECTS)
	$(CC) $(OBJECTS) -o assignment4

PPlot.o: PPlot.cpp PPlot.h
	$(CC) $(FLAGS) -c lib/PPlot.cpp

SVGPainter.o: SVGPainter.cpp SVGPainter.h
	$(CC) $(FLAGS) -c lib/SVGPainter.cpp

test.o: test.cpp sort.h
	$(CC) $(FLAGS) -Ilib -c src/test.cpp

main.o: main.cpp sort.h
	$(CC) $(FLAGS) -Ilib -c src/main.cpp

clean:
	rm assignment4 *.o *.svg
