/* Author: Syed Alfran Ali */

/* Implementing Modified Caesar cipher Encryption and than Decrypting it by cracking the Key. */

/* Implements any type of string characters either any special character or not, i.e. below program is not only constraint to alphabets both lower and upper case too. */
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
        int i;
        char deCrypted[100];
        cout << "Enter the string\n";
	scanf("%[^\n]s",deCrypted);
	int n = strlen(deCrypted);
        int key;
        cout << "Enter the key\n";
        cin >> key;
        char enCrypted[n+1];
        for(i=0;i<n;i++)
        {
		/* Handling for spaces */
                if(deCrypted[i]==' ')
                {
                         enCrypted[i] = ' ';
                         continue;
                }
		/* Handling for special symbols like @,#,$ ...*/
		if((deCrypted[i] > 'Z' && deCrypted[i] < 'a') || deCrypted[i] < 'A')
		{
			enCrypted[i] = deCrypted[i];
		}
		if(deCrypted[i] > 'z' || (deCrypted[i] < 'a' && deCrypted[i] > 'Z'))
		{
			enCrypted[i] = deCrypted[i];
		}
		/* Handling for lower case alphabets */
                if(deCrypted[i]<='z' && deCrypted[i]>='a')
                {
                        enCrypted[i] = (deCrypted[i] + key);
                        if(enCrypted[i]>'z')
                        {
                            enCrypted[i] = deCrypted[i] - 'z' + 'a' +2 ;
                        }
                }
		/* Handling for upper case alphabets */
                if(deCrypted[i]<='Z' && deCrypted[i]>='A')
                {
                        enCrypted[i] = deCrypted[i] + key;
                        if(enCrypted[i]>'Z')
                        {
                            enCrypted[i] = deCrypted[i] - 'Z' + 'A' + 2;
                        }
                }
        }
	/* Printing out the Encrypted Text */
        for(i=0;i<n;i++)
        {
                cout << enCrypted[i];
        }
        cout << endl;

	/* Getting the --crack */
	for(i=0;i<n;i++)
	{
		/* Handling for spaces */
                if(deCrypted[i]==' ')
                {
                         deCrypted[i] = ' ';
                         continue;
                }
		/* Handling the special character cases */
		if(enCrypted[i]-deCrypted[i] < 0)
		{
			deCrypted[i] =  enCrypted[i] + (deCrypted[i]- enCrypted[i]);
		}
		if(enCrypted[i]-deCrypted[i] > 0)
		{
			deCrypted[i] =  enCrypted[i] - (enCrypted[i] - deCrypted[i]);
		}

	}
	/* Printing the cracked value i.e. The Plain Text(Original)*/
	for(i=0;i<n;i++)
	{
		cout << deCrypted[i] ;
	}
	cout << endl;

}
