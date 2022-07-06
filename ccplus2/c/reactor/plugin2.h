#include <stdio.h>

asm(".Global alias_data");
asm("alias_data = data");

extern int alias_data[];

void func_stage1(void)
{
	printf("libplugin.so: func_stage1 is called. \n");
	
	*(alias_data + 0) = 100;
	*(alias_data + 1) = 200;
}
