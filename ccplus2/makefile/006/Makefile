.PHONY:clean

libaTest:
	$(CXX) -c aTest.cpp -o aTest.o
	$(AR) -r libaTest.a aTest.o
	$(RM) aTest.o

clean:
	$(RM) *.o *.a