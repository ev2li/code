#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>	

// defined in libplugin.so
typedef void (*pfunc_init)(int *);
typedef void (*pfunc_stage1)(void);

int data[100] = { 0 };


void main(void)
{
	data[0] = 10;
	data[1] = 20;

	printf("data[0] = %d \n", data[0]);
	printf("data[1] = %d \n", data[1]);
	
	// open libplugin.so
	void *handle = dlopen("./libplugin.so", RTLD_NOW);
	if (!handle)
	{
		printf("dlopen failed. \n");
		return;
	}

	// get and call routine function in libplugin.so
	pfunc_stage1 func_stage1 =  (pfunc_stage1) dlsym(handle, "func_stage1");
	if (!func_stage1)
	{
		printf("get func_stage1 failed. \n");
		return;
	}
	func_stage1();

	printf("data[0] = %d \n", data[0]);
	printf("data[1] = %d \n", data[1]);

	return;
}
