/*
	Author: Syed Alfran Ali
            Simple Columnar Transposition Technique
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string pt;
	int i;
	cout << "Enter the plain text without space: \n";
	cin >> pt;
	cout << endl;
	string sequence;
	cout << "Enter a sequence having numbers 1 to 5\n";
	cin >> sequence;
	cout << endl;
	/* Condition checking */
	if(sequence.length() == 5)
	{
		int checker[5]={0},inDex;
		for(i=0;i<5;i++)
		{
			inDex = sequence[i]-48;
			if(inDex < 6) checker[inDex-1] = 1;
		}
		for(i=0;i<5;i++)
		{
			if(checker[i] == 0)
			{
				cout<<"Wrong Sequence"<<endl;
				return 0;
			}
		}
	}
	else
	{
		cout << "Wrong sequence" << endl;
		return 0;
	}

	/* Forming cipher text */
	string ct = "";
	int col=0,inDex = 0,l = pt.length();
	for(i=0;i<5;i++)
    {
        col = sequence[i]-48;
        inDex = col-1;
        while(inDex < l)
        {
            ct += pt[inDex];
            inDex += 5;
        }
    }
    cout << "Encrypted Text is :\n" << ct << "\n" <<endl;
	return 0;
}

