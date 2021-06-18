#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o student.o TOEFLscore.o Dstudent.o node.o list.o
	g++ -g -o main main.o student.o TOEFLscore.o Istudent.o Dstudent.o sort.o node.o list.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c -std=c++11 main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c -std=c++11 student.cpp

TOEFLscore.o: TOEFLscore.cpp
	g++ -g -c -std=c++11 TOEFLscore.cpp

Istudent.o: Istudent.cpp
	g++ -g -c -std=c++11 Istudent.cpp

Dstudent.o: Dstudent.cpp
	g++ -g -c -std=c++11 Dstudent.cpp

sort.o: sort.cpp
	g++ -g -c -std=c++11 sort.cpp

node.o: node.cpp
	g++ -g -c -std=c++11 node.cpp

list.o: list.cpp
	g++ -g -c -std=c++11 list.cpp

#remove built files
clean:
	rm -rf main main.o student.o TOEFLscore.o Istudent.o Dstudent.o sort.o node.o list.o *~
