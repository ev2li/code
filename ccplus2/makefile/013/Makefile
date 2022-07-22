A:=123321
RS1:=
RS2:=
RS3:=
RS4:=
ifeq ($(A), 123) #ifeq和()之间要有空格
	RS1:=123
else
	ifeq ($(A), 321)
		RS1:=321
	else
		RS1:=no-123-321
	endif
endif #没有elseif，如果要实现只能嵌套

ifndef A
	RS3=yes
else
	RS3=no
endif

ifndef FLAG
	FLAG:=default
endif

all:
	echo $(RS1) $(RS3) $(FLAG)