#include <iosLib.h>

typedef struct {
DEV_HDR devHdr;
int mode;
int* number;
} PEDEV;

int PECreat(PEDEV * desc, char * name, int flag);
int PERemove(PEDEV * desc, char * name);
int PEOpen(PEDEV * desc, char * name, int flag);
int PEClose(PEDEV * desc, char * name);
int PERead (PEDEV * desc, char * buff, int nBytes);
int PEWrite (PEDEV * desc, char * buff, int nBytes);
int PEIOCtl (PEDEV * desc, int fonction, int arg);
