#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFSIZE 8192

int main(int argc, char *argv[])

{

        int fd;
        int fd2;
	int fd_r;
        int n;
        char buf[BUFFSIZE];
	char buf2[BUFFSIZE];

	int nul_v;

        if (argc == 1) {

                fputs("에러. \n", stderr);
                exit(1);

        }

        fd = open(argv[1], O_RDONLY, 0644);
        fd2 = open(argv[2], O_RDONLY, 0644);

	while((n=read(fd, buf, 4))>0)
		nul_v=1;
	while((n=read(fd2, buf2, 5))>0)
		nul_v=1;

	close(fd);
	close(fd2);

	fd_r = creat("result", 0644);
	write(fd_r, buf, 4);
	lseek(fd_r, 10, SEEK_SET);
	write(fd_r, "fighting!\n", 10);
	write(fd_r, buf2, 5);
	lseek(fd_r, 5, SEEK_CUR);
	write(fd_r, "fighting!\n", 10);

	close(fd_r);
}
