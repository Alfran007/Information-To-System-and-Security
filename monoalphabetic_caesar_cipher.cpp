/* Author: Syed Alfran Ali */

// Implementing Encryption Mono-alphabetic Caesar cipher

#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int main(void)
{
        int n,i,temp,lastIndex,temp2;
        char deCrypted[1000];
	time_t t;
        int store[30];
        int key[26]={0};
        cout << "Enter the string" << endl;
        scanf("%[^\n]s",deCrypted);
	n = strlen(deCrypted);
	char keY[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	lastIndex = 25;
        for(i=0;i<=25;i++)
        {
                store[i] = 0;
        }
	srand((unsigned) time(&t));
        char enCrypted[n+1];
        for(i=0;i<n;i++)
        {

                if(deCrypted[i]==' ')
                {
		         enCrypted[i] = ' ';
		         continue;
                }
		if(deCrypted[i]>'z' || deCrypted[i]<'a')
		{
			enCrypted[i] = deCrypted[i];
			continue;
		}
                if(deCrypted[i]<='z' && deCrypted[i]>='a')
                {
                        if(store[deCrypted[i]-'a']==0)
                        {

				temp = rand()%(lastIndex + 1);
                                enCrypted[i] = keY[temp];
				temp2 = keY[lastIndex];
				keY[lastIndex] = keY[temp];
				keY[temp] =  temp2;
				lastIndex--;
                                key[deCrypted[i] - 97] = enCrypted[i];
				store[deCrypted[i] - 97]=1;
                        }
                        else
                        {
                                enCrypted[i] =  key[deCrypted[i]- 97];
                        }
                }
        }
        for(i=0;i<n;i++)
        {
              cout << enCrypted[i];
        }
        cout << endl;

}

