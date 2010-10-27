#include "driver.h"
#include "string.h"
#include "stdlib.h"

int PECreat(PEDEV * desc, char * name, int flag)
{
	desc->number = malloc(sizeof(int));
	*(desc->number) = 0;
	return (int)desc;
}

int PERemove(PEDEV * desc, char * name) 
{
	free(desc->number);
	return OK;
}

int PEOpen(PEDEV * desc, char * name, int flag) 
{
	desc->number = malloc(sizeof(int));
	*(desc->number) = 0;
	return (int)desc;
}

int PEClose(PEDEV * desc, char * name)
{
	free(desc->number);
	return OK;
}

int PERead (PEDEV * desc, char * buff, int nBytes) 
{
	if ( nBytes >= sizeof(int) )
	{
		*buff = *(desc->number);
		return sizeof(*(desc->number));
	}
	return ERROR;
}

int PEWrite (PEDEV * desc, char * buff, int nBytes) 
{
	desc->number += (int)*buff;
	return OK;
}

int PEIOCtl (PEDEV * desc, int fonction, int arg) 
{
	return OK;
}