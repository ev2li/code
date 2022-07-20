# OBJ=add.o sub.o mutli.o calc.o
OBJ=$(patsubst %.cpp, %.o, $(wildcard ./*.cpp))
TARGET=calc

#伪目标 .PHONY:clean
#声明目标为伪目标之后，makefile将不会判断目标是否存在或该目标是否需要更新
.PHONY:clean show

$(TARGET):$(OBJ)
	$(CXX) $^ -o $@
	@rm -rf *.o 

#模式匹配 %.目标:%.依赖
#目标和依赖相同部分，可用%.来通配
%.o:%.cpp
	$(CXX) -c  $^ -o $@

clean:
	@$(RM) $(TARGET) *.o

show:
	echo $(AS)
	echo $(CC)
	echo $(CPP)
	echo $(CXX)
	echo $(RM)
	echo $(wildcard ./*.cpp)
	echo $(patsubst %.cpp, %.o, $(wildcard ./*.cpp))