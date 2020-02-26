#include <wiringSerial.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, int *argv[]) //int serialOpen (const char *device, const int baud)
{
    int fd;
    char ctl=50;
    if((fd = serialOpen("/dev/ttyAMA0", 115200)) < 0)
    {
        fprintf(stderr,"Unable to open serial device: %s\n", strerror(errno));
        return 1;
    }

    //serialPuts(fd, "Usart send Test,Just by launcher!");
    serialPutchar(fd, ctl);
    return 0;
}
