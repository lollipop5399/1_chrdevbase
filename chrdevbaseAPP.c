#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/*

*/
int main(int argc, char *argv[])
{
    int ret=0;
    int fd=0;
    char *filename;
    filename = argv[1];
    char readbuf[100],writebuf[100];
    static char usrdata[]={"user data !!!"};
    if(argc != 3){
        printf("Error usage!!!\r\n");
        return -1;
    }

    fd = open(filename, O_RDWR);
    if(fd<0)
    {
        printf("Can't open file %s\r\n",filename);
        return -1;
    }

    /*read*/
    if(strcmp(argv[2],"-r")==0){
        ret = read(fd, readbuf, 50);
        if(ret<0)
        {
            printf("Read file %s fialed!!!\r\n",filename);
        }
        else{
            printf("APP read data:%s\r\n",readbuf);

        }
    }
    

    /**
     * 
     *write
    */
   if(strcmp(argv[2],"-w")==0){
        memcpy(writebuf,usrdata,sizeof(usrdata));
        ret = write(fd, writebuf, 50);
        if(ret<0){
            printf("Write file %s fialed!!!\r\n",filename);
        }else{


        }

   }
    
    /*close*/

    ret = close(fd);
    if(ret<0){
        printf("Close file %s fialed!!!\r\n",filename);
    }

    return 0;
}
