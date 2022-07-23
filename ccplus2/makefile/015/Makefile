# 自定义函数，不是真正的函数，本质上是多行命令，放在外面了

.PHONY:clean

A:=123
B:=$(A)
define FUNC1
	echo $(0)
	echo $(1) $(2) $(3)
	# echo func1
	# echo $(A) $(B)
endef

A:=789

define FUN3
	echo $(shell ls)
endef

LS:=$(call FUN3)

default:
	# $(call FUN3)
	echo $(LS)

all:
	$(call FUNC1, abc,def,$(A))

clean:
	$(RM) *.txt