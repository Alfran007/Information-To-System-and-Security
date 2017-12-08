/* Author : Syed Alfran Ali */

/* Perform chaining Block Cipher
 plainText is "welcome to cryptography and network security"
 initializationVector is 101010101010....
 key=4
 encryption algorithm is ceaser cipher. */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char pt[100];
	scanf("%[^\n]%*c",pt);
	//pt = "welcome to cryptography and network security\0";
	int key=4;
	/*I used 8 bit value which is 170 and xor with each block in beginning only so below IV is not required*/
	char IV[]="1010101010101010101010101010101010101010101010101010101010101010";
	int lpt=strlen(pt);
	//int lk=strlen(pt);
	int pading,key_pad;
	if(lpt%8!=0)
	{
		pading=(lpt%8);
	}
	for(int i=0;i<pading;i++)
	{
		pt[i+lpt]='0';
	}
	pt[lpt+pading]='\0';
	lpt=strlen(pt);
	char enCrypted[100],deCrypted[100];
	for(int i=0;i<8;i++)
	{
		enCrypted[i]=pt[i]^170;
	}
	for(int i=0;i<8;i++)
	{
		enCrypted[i]=(enCrypted[i]+4)%255;

	}
	int count=1,i,j;
	/* Block formation , Encryption with the encrypted IV and Plain Text */
	while(count<=6)
	{
	   i=8*count,j;
		j=i+8;
		while(i<j)
		{
			enCrypted[i]=pt[i]^enCrypted[i-8];
			/* Encypted go beyond range so mod with 255 */
			enCrypted[i]=(enCrypted[i]+4)%255;
			i++;
		}
		count++;
	}
	enCrypted[i]='\0';
	/* Plain Text to Encrypted */
	//cout << enCrypted << endl;
	/* Decryption from the encrypted text, below is the first blocks decryption */
	for(int i=0;i<8;i++)
	{
		deCrypted[i]=(enCrypted[i]-4)%255;
	}
	for(int i=0;i<8;i++)
	{
		deCrypted[i]=deCrypted[i]^170;
	}
	count=1;
	/* Decryption of other 5 blocks */
	while(count<=5)
	{
		i=8*count,j;
		j=i+8;
		while(i<j)
		{

			deCrypted[i]=(enCrypted[i]-4)%255;
			deCrypted[i]=deCrypted[i]^enCrypted[i-8];
			i++;
		}
		count++;
	}
	deCrypted[lpt-pading]='\0';
	cout << "Decrypted Text is:" << endl;
	cout << deCrypted << endl;
	return 0;
}
