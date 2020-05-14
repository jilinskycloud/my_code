#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <error.h>
#include <errno.h>


int main(){
        int fd;
	int wlen;
	unsigned char buf[80];
	struct termios config;
        const char dev[] = "/dev/ttymxc2";
	// Open serial device
        fd = open(dev, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
        if(fd == -1){
                printf("Can't Open the device! \n");
        }
	if(!isatty(fd)){
		printf("This is not a tty Device!\n");
	}
	// Get current Configuration
	if(tcgetattr(fd,&config) < 0){
		printf("There is an error getting attributes!\n");
	}

	// Setting up input and output flags
	config.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | INPCK | ISTRIP | IXON);
	config.c_oflag = 0;
	// No Line processing
	config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);
	// Turn off the line processing
	config.c_cflag &= ~(CSIZE | PARENB | CSTOPB);
	config.c_cflag |= CS8;

//	printf("file status = 0x%x\n", fcntl(fd, F_GETFL, 0));
	//config.c_cc[VMIN] = 0;
	//config.c_cc[VTIME] = 5;
	//fcntl(fd,F_SETFL,FNDELAY);		 //CONVERT TO BLOCKING MODE
	//fcntl(fd,F_SETFL,FNDELAY); // convert to non-blocking mode
	// Set Communication Speed
	if(cfsetispeed(&config, B115200) < 0 || cfsetospeed(&config, B115200) < 0){
		printf("Can't set I/O sped!\n");
	}
	// Apply the Configurations
	if(tcsetattr(fd, TCSAFLUSH, &config) < 0){
		printf("Configuration is not applied!\n");
	}
//         while(1){
	// Write Function
		wlen = write(fd, "Hello!", 6);
		if (wlen != 6) {
			printf("Error from write: %d, %d\n", wlen, errno);
		}
		tcdrain(fd);    
//		printf("Data Wrote!!!!\n");
	// Read Function
//}
int a = 1;
//	do{
//a = 0;	
	//	usleep(10000);
		int rdlen = read(fd, buf, sizeof(buf) - 1);
		if (rdlen == 42) {
			#ifdef DISPLAY_STRING
				buf[rdlen] = 0;
		//		printf("Read %d: \"%s\"\n", rdlen, buf);
			#else 
				unsigned char   *p;
		//		printf("Read %d:", rdlen);
				for (p = buf; rdlen-- > 0; p++)
				printf(" %x", *p);
				printf("\n");
			#endif
		} 
/*
		else if (rdlen < 0) {
			printf("Error from read: %d: %s\n", rdlen, strerror(errno));
		} else {  // rdlen == 0 
			printf("Timeout from read\n");
		}   
 */           
//	} while (a == 1);
//}
	close(fd);
        return 0;
}
