maze : main.o MazeImplementation.o StackImplementation.o
	gcc -o maze main.o MazeImplementation.o StackImplementation.o
main.o : main.c MazeInterface.h
	gcc -c main.c
MazeImplementation.o : MazeImplementation.c MazeInterface.h
	gcc -c MazeImplementation.c
StackImplementation.o : StackImplementation.c StackInterface.h
	gcc -c StackImplementation.c
clean :
	rm main.o MazeImplementation.o StackImplementation.o
