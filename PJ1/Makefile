PJ1	:main.o util.o list_read.o list_write.o
	 g++ -g -Wall -o PJ1 main.o util.o list_read.o list_write.o

main.o	:main.cpp data_structures.h util.h list_read.h list_write.h
	 g++ -g -Wall -c main.cpp

util.o	:util.cpp data_structures.h util.h
	 g++ -g -Wall -c util.cpp

list_read.o	:list_read.cpp data_structures.h list_read.h
	 g++ -g -Wall -c list_read.cpp

list_write.o	:list_write.cpp data_structures.h list_write.h
	 g++ -g -Wall -c list_write.cpp

clean	:
	rm *.o PJ1
