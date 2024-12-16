#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
char addr[10],line[80],op[3];
int hexa,i,j,temp;
FILE *fp1,*fp2,*fp3;
fp1 = fopen("objcode.txt","r");
    fp2 = fopen("output.txt","w");
   
    while(1)
    {
    fscanf(fp1,"%s", line);
    if(line[0]=='T')
    {
    for(i=2,j=0;i<=7;i++,j++)
    addr[j]=line[i];
    addr[j]='\0';
    temp=strtol(addr,NULL,16);
    hexa=temp;
    i=12;
    while(line[i]!='\0')
    {
    if(line[i]=='^')
    i++;
    fprintf(fp2,"%x\t%c%c\n",hexa,line[i],line[i+1]);
    i=i+2;
    hexa=hexa+0x1;
    }
    }
        if(getc(fp1)==EOF)
            break;
        }
    fclose(fp1);
    fclose(fp2);
    printf("FINISHED\nCheck for file output.txt\n");
        
}
