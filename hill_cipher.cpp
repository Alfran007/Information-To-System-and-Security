/* Author: Syed Alfran Ali */

/* Implementation of Hill Cipher */
#include <iostream>
#include <strings.h>

using namespace std;

int main()
{
	string text,CT;
	int mat[3][1]= {0,0,0};
	int key[3][3] = {6, 24 ,1, 13, 16, 10, 20, 17, 15};
	int i,j,k;
	cout<<"Enter a text that you want to encrypt (size = 3): ";
	cin>>text;

	for(i=0;i<3;i++)
		text[i] -= 'a';

	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			for(k=0;k<3;k++)
			{
				mat[i][j] += key[i][k] * (text[k]);
			}
		}

	}

	for(i=0;i<3;i++)
		mat[i][0] %= 26;

	for(i=0;i<3;i++)
		CT += mat[i][0] + 'a';

	cout<<"The cipher text is: "<<CT<<"\n";

}

