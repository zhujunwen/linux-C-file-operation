#include "zje.h"

/*文件复制操作*/
int zje_copy_file(char *src,char *des)
{
	int fd1,fd2;
	int len;
	char buf[1024]={0};

	fd1 = open(src,O_RDWR);
	if(fd1 == -1)
	{
		perror("failed to open src file");
		return -1;
	}

	fd2 = open(des,O_RDWR|O_CREAT);
	if(fd2 == -1)
	{
		perror("failed to open des file");
		return -1;
	}

	while(len = read(fd1,buf,1024))
	{
		write(fd2,buf,len);
		printf("len = %d\n",len);
	}
	return 0;
}
