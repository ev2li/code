# make 1
# make install 2 3 4 
# make clean 5
# 1.make:将源文件编译成二进制可执行文件(包括各种库文件)
# 2.创建目录，将可执行文件拷贝到指定目录(安装目录)
# 3.加全局可执行路径
# 4.全局的启停脚本
# 5.重置编辑环境，删除无关文件

.PHONY:clean install

TARGET:=test-main
OBJ:=$(TARGET).o
PATHS:=/tmp/main/
BIN:=/usr/local/bin/
CC=/usr/bin/g++
START_SH:=$(TARGET)_start
STOP_SH:=$(TARGET)_stop
LOG:=$(PATHS)$(TARGET).log
$(TARGET):$(OBJ)

install:$(TARGET)
	if [ -d $(PATHS) ];\
	    then echo $(PATHS) exist;\
	else\
	    mkdir $(PATHS);\
		cp $(TARGET) $(PATHS);\
		ln -sv $(PATHS)$(TARGET) $(BIN);\
		touch $(LOG);\
		chmod a+rwx $(LOG);\
		echo "$(TARGET) > $(LOG) &"> $(PATHS)$(START_SH);\
		echo "killall $(TARGET)" > $(PATHS)$(STOP_SH);\
		chmod a+x $(PATHS)$(START_SH);\
		chmod a+x $(PATHS)$(STOP_SH);\
		ln -sv $(PATHS)$(START_SH) $(BIN);\
		ln -sv $(PATHS)$(STOP_SH) $(BIN);\
	fi;\

clean:
	$(RM) $(TARGET) $(OBJ) $(BIN)$(TARGET) $(BIN)$(START_SH) $(BIN)$(STOP_SH)
	$(RM) -rf $(PATHS)