/* Author: Syed Alfran Ali */
/* Implementation of Counter Based Encryption */

#include<stdio.h>
#include<string.h>

int main()
{
    char t[8]="!@#$%^&*",pt[1024];
    int r[8];
    scanf("%[^\n]s ",pt);
    int i,n=strlen(pt),m=(n-1)/8,k=13,j;
    int  ct[n];
    ct[n]='\0';
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<8;j++)
        {
            r[j]=t[j]+k;
        }
        for(j=0;j<8;j++)
        {
            if(i*8+j>n)
                break;
            ct[i*8+j]=r[j]^((int)pt[i*8+j]);
        }
        t[7]=(t[7]+1)%8;
    }
    for(i=0;i<n;i++)
        printf("%d ",ct[i]);


}
