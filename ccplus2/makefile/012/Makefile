A:=$(shell ls ../)
B:=$(shell pwd)
FILE:=abc
C:=$(shell if [ ! -f $(FILE) ];then touch abc; fi;)

a:
	echo $(A) $(B) $(C)

clean:
	$(RM) $(FILE)

.PHONY:clean