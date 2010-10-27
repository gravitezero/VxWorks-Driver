#include "stdio.h"
#include "stdlib.h"
#include "driver.h"
#include "errno.h"

#define DEVICE_NAME "pe_dev"

int PEdrv_install()
{
	return iosDrvInstall( &PECreat, &PERemove, &PEOpen, &PEClose, &PERead, &PEWrite, &PEIOCtl);
}

int PEdev_add(char* name, int drvNumber)
{
	PEDEV * desc = (PEDEV *)malloc(sizeof(PEDEV));
	if((int)desc == NULL)
	{
		perror("Malloc");
		exit(errno);
		
	}
	return iosDevAdd((DEV_HDR*)desc, name, drvNumber);
}

int PEdev_del(char* name)
{
	
	DEV_HDR * pDevHdr;
	char* suite [1];
	pDevHdr = iosDevFind(name,suite);
	
	if ((pDevHdr!= NULL) && (*suite[0]=='\0')){
		iosDevDelete( pDevHdr );
		free(pDevHdr);
		return OK;
	}
	return ERROR;
}

void PEdrv_uninstall(int maj)
{
	iosDrvRemove(maj, FALSE);
	
}



int begin_test()
{
	int maj = PEdrv_install();
	if( PEdev_add(DEVICE_NAME, maj))
	{
		printf("Error while adding a device.\n");
		exit(EXIT_FAILURE);
	}
	return maj;
}

void end_test(int maj)
{
	if( PEdev_del(DEVICE_NAME))
	{
		printf("Error while removing the device.\n");
		exit(EXIT_FAILURE);
	}
	PEdrv_uninstall(maj);
}

void add_remove()
{
	int maj = begin_test();
	end_test(maj);
}

int open_dev(int* maj)
{
	int fd;
	*maj = begin_test();
	fd = open(DEVICE_NAME,O_RDWR,0777);
	
	if(fd == -1)
	{
		printf("Error on opening device.\n");
		exit(EXIT_FAILURE);
	}
	return fd;
}

void close_dev(int maj, int fd)
{
	close(fd);
	end_test(maj);
}
void open_close()
{		
	int maj;
	int fd = open_dev(&maj);
	close_dev(maj,fd);
}

int dev_read(int fd)
{
	int char_read = 0;
	int buffer = -1;
	
	char_read = read(fd, (char*) &buffer, sizeof(buffer));
	if(char_read != sizeof(buffer))
	{
		printf("Error on read.\n");
		exit(EXIT_FAILURE);
	}
	return buffer;
}

void dev_write(int fd, int buffer)
{
	int char_write = 0;
	
	char_write = write(fd, (char*)&buffer, sizeof(buffer));
	if(char_write != sizeof(buffer))
	{
		printf("Error on write.\n");
		exit(EXIT_FAILURE);
	}
}

void read_write()
{
	int maj = 0;
	int fd = 0;
	int buffer = -1;

	int char_write = 0;
	
	fd = open_dev(&maj);

	if(fd < 0)
	{
		printf("Error on opening device.\n");
		exit(EXIT_FAILURE);
	}
	
	buffer = dev_read(fd);
	if(buffer != 0)
	{
		printf("Error in initialization, buffer is %d\n", buffer);
		exit(EXIT_FAILURE);
	}
	
	buffer++;
	
	dev_write(fd, buffer);
	
	if(dev_read(fd) != 1)
	{
		printf("Error : bad value.\n");
		exit(EXIT_FAILURE);
	}
	
	close_dev(maj,fd);
}