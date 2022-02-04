#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("enter ./hack2hex filename.hack filename.hex\n");
        exit(EXIT_FAILURE);
    }

    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL){
        perror("fin fails");
        exit(EXIT_FAILURE);
    }
    FILE *fout = fopen(argv[2],"w");
    if(fin == NULL){
        perror("fout fails");
        exit(EXIT_FAILURE);
    }

    char instruction[64];
    char *status;
    char *endptr;

    unsigned short address = 0;
    unsigned short number;
    unsigned char addressH;
    unsigned char addressL;
    unsigned char numberH;
    unsigned char numberL;
    unsigned char checksum;

    do{
        status = fgets(instruction, sizeof(instruction),fin);
        if(status != NULL){
            number = (unsigned short)strtol(instruction, &endptr, 2);
            numberH = (unsigned char)((number & 0xFF00)>>8);
            numberL = (unsigned char)((number & 0x00FF));
            addressH = (unsigned char)((address & 0xFF00)>>8);
            addressL = (unsigned char)((address & 0x00FF));
            checksum = ((0x02 + numberH + numberL + addressH + addressL)^0xFF) + 1;
            fprintf(fout, ":02%02X%02X00%02X%02X%02X\n",addressH,addressL,numberL,numberH,checksum);
            address = address + 2;
        }
    }while (status !=NULL);
    exit(EXIT_SUCCESS);
}
