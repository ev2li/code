# -C 指定工作目录

DIR=../008 ../009#
all:$(DIR)

$(DIR):
	$(MAKE) -C $@

all-v1:
	$(MAKE) -C ../008
	$(MAKE) -C ../009

.PHONY:clean ../008 ../009

clean:
	$(shell for dir in $(DIR); do make -C $$dir clean;done) 
	
#$$表示展开shell中的变量
