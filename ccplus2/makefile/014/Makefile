#循环
#Makefile中只有一个循环，foreach
#可以在循环中逐个修改值

.PHONY:clean

TARGET:=a b c d
FILE:=$(foreach v, $(TARGET), $v.txt)
all:
	# echo $(TARGET)
	# echo $(foreach v, $(TARGET), $v)
	# touch $(TARGET)
	# touch $(foreach v, $(TARGET), $v.txt)
	# echo $(FILE)
	# for v in $(TARGET); \
	#	do touch $$v.txt; \
	# done; \
	$(shell for v in $(TARGET); do touch $$v.txt;done)
	
clean:
	$(foreach v, $(TARGET), $(RM) $v.txt)
	# $(RM) $(TARGET)