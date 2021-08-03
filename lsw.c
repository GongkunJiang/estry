#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#if 1
#include <mbedtls/compat-2.x.h>
#else
#endif


int main(int argc ,char ** argv)

{
    unsigned
	unsigned char out[16] = {0};
	
	int fd = open(argv[1],O_RDWR);
	if(fd < 0)
	{
		printf("----%d",fd);
		perror("open");
		return -1;
	}

	int seek = lseek(fd,0,SEEK_END);
	printf("seek is %d\n",seek);
	lseek(fd,0,SEEK_SET);


	char * p = malloc(seek);
	printf("point is %p ",p);


	int res = read(fd , p , seek);
	printf("res is %d \n",res);

	res = mbedtls_md5_ret(p , seek,out)	;
	printf(" res is %d",res);
	int i = 0;
	printf("md5:\n");
	for(;i < 16 ;i ++)
	printf("%02x",out[i]);
	printf("\n");

}
