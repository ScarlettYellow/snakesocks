#include "kokke_aes.h"

#include <stdio.h>
#include <string.h>



int main(void){
    unsigned char src[16]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned char key[16]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
    unsigned char cip[16];
    AES_ECB_encrypt(src,key,cip,16);
    for(int i=0;i<16;i++)
        printf("%u ",(unsigned int)cip[i]);
    return 0;
}