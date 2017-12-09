/* Author: Syed Alfran Ali */
/* Implementation of Vigenere Cipher */

#include<stdio.h>
/* You need this library or change the input/output functions*/
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void strk(string ks,int k[]);
int main(int argc,string argv[])
{
    if((argc>2 || argc<1)|| argv[1]==NULL )
    {
        printf("%s",argv[0]);
        return 1;
    }
    else
    {   int i,j,a,b,n1,n2;
        string ks=argv[1];
        n1=strlen(ks);
        int k[100];
        strk(ks,k);
        string p=GetString();
        int k1[strlen(p)];

		for(i=0,a=0;i<strlen(p);i++)
		{
		    if((p[i]>='a'&& p[i]<='z')||(p[i]>='A'&& p[i]<='Z'))
			{
			    k1[a]=i;
			    a++;
			}
		}
		n2=a;
		int k2[strlen(p)];
		for(i=0;i<n2;i++)
		{
			if(i>=n1)
				k[i]=k[i-n1];
		}
		b=0;
		for(i=0;b<n2;i++)
		{
			if(b==i)
				k2[k1[b]]=k[i];
			else
				k2[i]=0;
			b++;
		}
		for(i=0;i<strlen(p);i++)
		{
			if((p[i]>='a'&& p[i]<='z')||(p[i]>='A'&& p[i]<='Z'))
			{
				for(j=0;j<k2[i];j++)
				{
					if(p[i]=='z')
						p[i]='a';
					else if(p[i]=='Z')
						p[i]='A';
					else
						p[i]=p[i]+1;
				}
			}
		}
		printf("%s\n",p);
    }
}
void strk(string ks,int k[])
{   int i;
    for(i=0;ks[i]!='\0';i++)
    {
        if(ks[i]>='a' && ks[i]<='z')
        {
            k[i]=(char)(ks[i]-97);
        }
        else if(ks[i]>='A' && ks[i]<='Z')
        {
            k[i]=(char)(ks[i]-65);
        }
        else
        {
            printf("Retry");
            exit(1);
        }
    }
}
