#include<stdio.h>
//lseek
#include<sys/types.h>
#include<unistd.h>
//open read
#include<fcntl.h>
//malloc
#include<stdlib.h>

#include<md5.h>

int main(int argc, char ** argv)
{
	unsigned char out[16] = {0};
//	char * addr = "../testfile";
//	int fd = open(addr,O_RDWR);
	int fd = open(argv[1],O_RDWR);
	if(fd < 0)
	{
		printf("fd is %d.\n",fd);
		perror("open");
		return -1;
	}

	int seek = lseek(fd,0,SEEK_END);
	printf("seek is %d.\n",seek);
	lseek(fd,0,SEEK_SET);
	
	char * p = malloc(seek);
	printf("point is %p.\n",p);

	int res = read(fd,p,seek);
	printf("res is %d.\n",res);

	res = mbedtls_md5_ret(p,seek,out);
	printf("res is %d.\n",res);

	int i = 0;
	printf("md5:\n");
	for(;i < 16;i++)
		printf("%02x",out[i]);
	printf("\n");
}
