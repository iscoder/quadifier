INC=-I../common

default: quadifier.so

quadifier.so: main.cpp Log.h
	g++ -Wall -shared -fPIC $(INC) -o quadifier.so quadifier.cpp

clean:
	rm -r quadifier.so
