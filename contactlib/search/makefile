CPP=g++ -O3 --std=c++11 -fPIC

all: libsearch.so search

search: main.cpp Search.o Common.o Search.h Common.h
	$(CPP) -o $@ main.cpp Search.o Common.o -static

libsearch.so: Search.o Common.o
	$(CPP) -shared -o $@ Search.o Common.o

Search.o: Search.cpp Search.h Common.h
	$(CPP) -o $@ -c Search.cpp

Common.o: Common.cpp Common.h
	$(CPP) -o $@ -c Common.cpp

clean:
	rm -rf *.o search *.a
