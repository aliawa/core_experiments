
#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <string.h> 
#include <stdio.h> 

int main(int argc, char *argv[]) {

    char* fname=strchr(argv[1], ':');
    if (fname) {
        *fname='\0';
        ++fname;
        char* hname = argv[1];
        char remotecmd[50]={0};
        strcat(remotecmd, "cat >> ");
        strcat(remotecmd, fname);
        printf ("fname:%s, hname:%s, remotecmd:%s\n", fname, hname, remotecmd);
        execlp("/usr/bin/ssh", "ssh", hname, remotecmd, (char *)NULL);
    }
    //execlp("/usr/bin/ssh", "ssh", "aawais@lin.ewn", "cat >> /home/aawais/tmp/abc.txt", (char *)NULL);
    return 0;
}  
