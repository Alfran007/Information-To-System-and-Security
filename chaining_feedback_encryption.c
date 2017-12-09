/* Author: Syed Alfran Ali */
/* Implementation of chaining feedback Encryption */
#include<stdio.h>
#include<string.h>


int main()
{
    char iv[8]="ZXCVBNM<",pt[64];
    int r[8];
    scanf("%[^\n]s ",pt);
    int n=strlen(pt),i,j,k=8,s=16/8,l=0;
    char ct[n];
    for(i=0;i<n;i+=s)
    {
        for(j=0;j<8;j++)
        {
            r[j]=iv[j]+k;
        }
        for(j=0;j<s;j++)
        {
            ct[i+j]=pt[i+j]^r[j];
        }
        for(j=0;j<8-s;j++)
        {
            iv[j]=iv[j+s];
        }
        for(j=0;j<s;j++)
        {
            iv[j+8-s]=ct[i+j];
        }
        for(j=0;j<8;j++)
            printf("%d ",iv[j]);
        printf("\n");
    }
    ct[n]='\0';
   for(i=0;i<n;i++)
       printf("%d ",ct[i]);
}
