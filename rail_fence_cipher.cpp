/*
	Author: Syed Alfran Ali
                        */
/* Implementation of Rail Fence encryption */
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=0,l,k=0;
	string str;
	char pt[50000];
	cout << "Enter the plain Text\n";
	getline(cin, str);
	int le =str.length();
	/* Removing spaces */
	while(i<le)
    {
        if(str[i] == ' ')
        {
            i++;
            continue;
        }
        pt[k] =  str[i];
        i++;
        k++;
    }
	/* Getting the length of the plain text */
	l = strlen(pt);
	cout << endl;
	string ct;
	/* Adding the even place characters*/
	for(i=0;i<l;i+=2)
    {
        ct = ct + pt[i];
    }
    /* Adding the odd place characters */
	for(i=1;i<l;i+=2)
    {
        ct = ct + pt[i];
    }
    cout << "Encrypted Text is:" << endl;
	cout << ct << endl;
	return 0;
}

