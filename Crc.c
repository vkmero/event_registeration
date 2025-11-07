#include<stdio.h>
#include<string.h>

void Xor(char divident[],char divisor[],int pos){

    for(int i=0;divisor[i]!='\0';i++)
    {
        divident[i+pos]=(divident[i+pos] == divisor[i])?'0':'1';
    }
}
void Crc(char data[],char crc[],char poly[])
{
    int dataLen = strlen(data);
    int polyLen = strlen(poly);

    char temp[200];
    strcpy(temp,data);
    for(int i=0;i<polyLen-1;i++)
    {
        temp[dataLen+i]='0';

    }
    for(int i=0;i<dataLen;i++)
    {
        if(temp[i]=='1')
        {
            Xor(temp,poly,i);
        }
    }

    strncpy(crc,&temp[strlen(temp)],polyLen-1);
    crc[polyLen-1]='\0';
}
int main(){

    char crc[100];
    char data[100];
    char transmitted[200];
    char recived[200];

    char crc12 []="1100000001111";
    char crc16[]="110000000000001001";
    char crcccip[]="10001000000100001";

    printf("Enter the data : ");
    scanf("%s",data);

    Crc(data,crc,crc12);

    strcpy(transmitted,data);
    strcat(transmitted,crc);

    printf("The data transmitted is : %s",transmitted);

    char checkCrc[20];
    printf("enter the transmitted is : ");
    scanf("%s",recived);

    Crc(recived,checkCrc,crc12);

    int error =0;
    for(int i=0;i<strlen(checkCrc);i++)
    {
        if(checkCrc[i]!='0')
        {
            error =1;
            break;
        }
    }

    if(!error){
        printf("The frame are sucessfull without errors");
    }
    else{
        printf("The error the error 404!!!");
    }
    
}