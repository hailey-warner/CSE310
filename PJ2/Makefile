PJ2	:main.o util.o heap.o
	 g++ -g3 -Wall -o PJ2 main.o util.o heap.o

main.o	:main.cpp data_structures.h util.h heap.h
	 g++ -g3 -Wall -c main.cpp

util.o	:util.cpp data_structures.h util.h
	 g++ -g3 -Wall -c util.cpp

heap.o	:heap.cpp data_structures.h heap.h
	 g++ -g3 -Wall -c heap.cpp

clean	:
	rm *.o PJ2
