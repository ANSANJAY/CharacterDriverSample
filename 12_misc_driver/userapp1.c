#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char *argv[])
{
	char buffer[1024];	
	int fd;
	unsigned int length;
	int i = 0;
	unsigned long addr;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}

	printf("Size:%d\n", _IOC_SIZE(MSG_GET_ADDRESS));
	printf("cmd:%u\n", MSG_GET_ADDRESS);

	ioctl(fd, MSG_GET_ADDRESS, &addr);
	perror("ioctl");
	getchar();
	printf("address:%x\n", addr);

	close(fd);
}
