/*
	Author: Syed Alfran Ali
         Electronic Code Book Algorithm Implementation
*/

#include<bits/stdc++.h>
using namespace std;

/* Convert binary string back to char string */
string bin2string(string binary,int check)
{
    int l = binary.length();
    int i,j;
    int bytes = l/8;
    string str = "";
    for(i=0;i<bytes;i++)
    {
        string temp = binary.substr(i*8,8);
        char flag = 0;
        for(j=0;j<8;j++)
        {
            flag = flag | (temp[j] == '1' ? (1 << (7-j)): 0);
        }
        if(check | flag != 0)
            str += flag;
    }
    return str;
}
/* Convert input string to binary string */
string string2bin(string str)
{
	int l = str.length();
	int i,j,k;
	string empt = "";
	for(i=0;i<l;i++)
	{
		string t = "";
		k = (int)str[i];
		for(j=0;j<8;j++)
		{
			t = (char)(k % 2 + 48) + t;
			k=k/2;
		}
		empt = empt + t;
	}
	return empt;
}


/* It adds extra 0s as padding */
string pad(string end_Block,int padding)
{
    end_Block.resize(end_Block.length()+ padding,'0');
    return end_Block;
}
/* Function for doing xor operation */
string XOR(string a,string b)
{
    if(a.length() != b.length())
        return "";
    int l = a.length();
    string result = "";
    for(int i=0;i<l;i++)
    {
        if(a[i] == b[i])
            result = result + '0';
        else
            result = result + '1';
    }
    return result;
}

int main()
{
	string pt;
    cout << "Input the text to encrypt:\n";
    getline(cin,pt);

	string key;
	cout << "Please enter the key:\n";
	getline(cin,key);

    /* Conversions */
	string binPt = string2bin(pt);
	string binaryKey = string2bin(key);

	/* Plain Text Blocks Generation */
    int P,K,i;
    P = binPt.length();
    K = binaryKey.length();
    int padding = K - P % K;
    if(padding == K)
    {
        padding = 0;
    }
    /* Creating vector of string for the blocks of plain text */
    vector<string> pt_partitions;
    for(i=0;i<P;i+=K)
    {
        if(i+K <= P)
        {
            pt_partitions.push_back(binPt.substr(i,K));
        }
        else
        {
            pt_partitions.push_back(pad(binPt.substr(i),padding));
        }
    }


	/* Encryption */
	vector<string> encry_partitions;
	int s = pt_partitions.size();
    for(i=0;i<s;i++)
    {
        encry_partitions.push_back(XOR(pt_partitions[i],binaryKey));
    }
    string encry_text = "";
	for(i=0;i<s;i++)
    {
        encry_text = encry_text + encry_partitions[i];
    }
    cout <<"Encrypted Text:\n" << encry_text << "\n" <<endl;


    /* Decryption */
    vector<string> decry_partitions;
	for(i=0;i<s;i++)
    {
        decry_partitions.push_back(XOR(encry_partitions[i],binaryKey));
    }
    string decry_text = "";
	for(i=0;i<s;i++)
        decry_text = decry_text + bin2string(decry_partitions[i],0);
    cout<<"Decrypted text:\n" << decry_text << "\n"<<endl;

	return 0;
}
