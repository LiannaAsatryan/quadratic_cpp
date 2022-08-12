main: quadr.o
	g++ main.cpp quadr.o -o main
	./main

all: test clean

test: target
	./target

target: quadr.o
	g++ quadr_test.cpp quadr.o -o target

quadr.o: quadr.cpp
	g++ -c quadr.cpp -o quadr.o

clean: 
	rm -f main target output.txt result.txt quadr.o

