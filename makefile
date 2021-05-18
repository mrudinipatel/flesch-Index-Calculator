fleschIndex: fleschIndex.o main.o
	gcc -Wall -lm -std=c99 fleschIndex.o main.o -o fleschIndex

fleschIndex.o: fleschIndex.c fleschIndex.h
	gcc -Wall -lm -std=c99 -c fleschIndex.c

main.o: main.c fleschIndex.h
	gcc -Wall -lm -std=c99 -c main.c

clean:
	rm *.o fleschIndex
