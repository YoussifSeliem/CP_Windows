#include <stdio.h> 
#include <stdlib.h> 

int main(int argc , char **argv)
{
    if(argc<3)
        return 1;
        //returning 1 in case of the command isnot written completly

    FILE *srcFilePt = fopen(argv[1], "rb");
    if (srcFilePt==NULL)
        return 2;
        //returning 2 if there's issue with opening the source file
    
    FILE *dstFilePt = fopen(argv[2], "wb");
    if (dstFilePt==NULL)
        return 3;
        //returning 3 if there's issue with destination file

    //copying file process 
    char buffer[1];
    while (fread(buffer, sizeof(char), 1, srcFilePt))
    {
    //putting the chars of the source file in the buffer
        fwrite(buffer, sizeof(char), 1, dstFilePt);
    //writing the chats stored in the source file in the destination file
    }
    
    fclose(srcFilePt);
    fclose(dstFilePt);
}
