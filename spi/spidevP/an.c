#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <string.h> 
#include <spi.h>
static const char *device = "/dev/spidev0.0";


void main(){
  printf("testing\n");
  int file;
  if ((file = open(device,O_RDWR)) < 0)
  {
    printf("Failed to open the bus.\n");
    exit(1);
  }


  if(spidev_release(device,O_RDWR) < 0){
    printf("Device Released!\n");
  }



}
