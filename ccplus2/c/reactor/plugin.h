#include <stdio.h>

int *alias_data = NULL;

void func_init(int *data)
{
	printf("libplugin.so: func_init is called. \n");
	alias_data = data;
}

void func_stage1(void)
{
	printf("libplugin.so: func_stage1 is called. \n");
	if (alias_data)
	{
		alias_data[0] = 100;
		alias_data[1] = 200;
	}
}
