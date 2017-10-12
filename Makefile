all:	a01
a01:	eventLib.o dbLib.o processData.o main.o
			g++ eventLib.o dbLib.o processData.o main.o -o a01

eventLib.o:	eventLib.cpp
			g++ -c eventLib.cpp
dbLib.o:	dbLib.cpp
			g++ -c dbLib.cpp
processData.o:	processData.cpp
			g++ -c processData.cpp
main.o:		main.cpp
			g++ -c main.cpp
clean:
			rm -rf *o main