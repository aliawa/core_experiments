
#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int fd=-1;
    if((fd = open(argv[1], 
                    O_RDWR|O_CREAT, 
                    S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH))==-1){ 
        perror("open");
        return 1;
    }

    dup2(fd,1);

    execl("/usr/bin/gzip", "gzip", "-9", (char *)NULL);
    return 0;
}  
