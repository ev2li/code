#calc:
#	g++ add.cpp sub.cpp mutli.cpp calc.cpp -o calc

calc:add.o sub.o mutli.o
	g++ $^ calc.cpp -o $@
	@rm -rf *.o 

add:add.cpp
	gcc -c add.cpp -o add.o

sub:sub.cpp
	gcc -c sub.cpp -o sub.o

mutli:mutli.cpp
	gcc -c mutli.cpp -o mutli.o

clean:
	@rm -rf calc *.o