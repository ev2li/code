.PHONY:clean

TARGET=main
LDFLAGS=-L../004
LIBS=-lSoTest

$(TARGET):
	$(CXX) $(LDFLAGS) $(LIBS) main.cpp -o $($TARGET)

clean:
	$(RM) $(TARGET)