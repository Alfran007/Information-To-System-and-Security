/*
	Author: Syed Alfran Ali
*/
/* Enter the input in capitals only without having any space.
    Key Words:
    pt = Plain Text
    a = Array of key
    l = length
    cypher = Encrypted Plain Text
*/
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int var1,var2,counter=0,l,i,j;
	string key,pt;
    char a[5][5];
	cout << "Please enter the key without any space in capitals only" << endl;
	cin >> key;
	cout << "Please Enter the plain text without any space in capitals only" << endl;;
	cin >> pt;
	int letters[26];
    for(i=0;i<26;i++)
    {
        letters[i] = 0;
    }
    /* Storing the length of the key in l */
	l = key.length();

	/* Matrix Formation */
	for(i=0;i<l;i++)
	{
	    var1 = counter/5;
        var2 = counter%5;
	    if(letters[key[i]-65] == 0 && ( key[i] == 'I' || key[i] == 'J' ) )
        {
            counter++;
            letters['J'-65] = letters['I'-65] = counter;
            a[var1][var2] = 'I';
        }
		else if(letters[key[i]-65] == 0)
		{
			counter++;
			letters[key[i]-65] = counter;
			a[var1][var2] = key[i];
		}
	}
	for(i=counter,j=0;i<25;i++)
	{
		var1 = i/5;
		var2 = i%5;
		for(;j<26;j++)
            if(letters[j] == 0)
                {
                    letters[j] = i+1;break;
                }
        /* Type casting to change to corresponding char */
		if(j != 9 )a[var1][var2] = (char)(65+j);
		else
		{
			letters[j] = letters[j-1];
			i--;
		}
		j++;
	}

	/* If length is odd then adding 'X' */
	l = pt.length();
	string new_pt = pt;
    if(l%2 == 1)
    {
        new_pt+='X';
        l++;
    }

	/* If same element pair are occurring in strings then replacing the second character with 'X' */
    string temp="";
    for(i=0;i<l;i++)
    {
        temp+=new_pt[i];
        if(new_pt[i] == new_pt[++i])
        {
            temp = temp + 'X';
        }
        else
        {
            temp = temp + new_pt[i];
        }
    }

	/* Displaying the Key Matrix */
	cout<< "Matrix formed from the key :" << endl;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

	/* Encrypting to cypher text */
    int flag1,flag2,count1,count2;
    string cypher="";
    for(i=0;i<l;i++)
    {
        char char1=temp[i],char2=temp[++i];

        flag1=(letters[char1-65]-1)/5;
        flag2=(letters[char2-65]-1)/5;
        count1=(letters[char1-65]-1)%5;
        count2=(letters[char2-65]-1)%5;

        if(count1 == count2)
        {
            char1 = a[(flag1+1)%5][count1];
            char2 = a[(flag2+1)%5][count1];
        }

        else if(flag1 == flag2)
        {
            char1 = a[flag1][(count1+1)%5];
            char2 = a[flag1][(count2+1)%5];
        }

        else
        {
            char1 = a[flag1][count2];
            char2 = a[flag2][count1];
        }
        /* Adding the encrypted text after each iteration in final string */
        cypher = cypher + char1;
        cypher = cypher + char2;
    }
    cout << "Cypher is : " << cypher << endl;
}

