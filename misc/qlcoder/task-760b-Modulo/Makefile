main : main.o modulo.o
	g++ --std=c++11 -O3 -o main main.o modulo.o

main.o : main.cpp modulo.h
	g++ --std=c++11 -O3 -c main.cpp

modulo.o : modulo.cpp modulo.h
	g++ --std=c++11 -O3 -c modulo.cpp

clean:
	rm main main.o modulo.o
