/* Author: Syed Alfran Ali */
/* Implementation of Output feedback Encryption */
#include<stdio.h>
#include<string.h>

int main()
{
    char iv[8]="1b2d3f4h",pt[1024],r[8];
    scanf("%[^\n]s ",pt);
    int i,n=strlen(pt);
    int m=n/8;
    int k=11,j;
    r[8]='\0';
    char ct[n];
    ct[n]='\0';
    //encrypt
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<8;j++)
        {
            if(i==0)
            {
                r[j]=(iv[j]-97+k)%26+97;
            }
            else
            {
                r[j]=(r[j]-97+k)%26+97;
            }
        }
        for(j=0;j<8;j++)
        {
            if(i*8+j>n)
                break;
            ct[i*8+j]=pt[i*8+j]^r[j];
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",ct[i]);
}
