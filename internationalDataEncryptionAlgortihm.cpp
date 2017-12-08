/*
	Author: Syed Alfran Ali
			---IDEA implementation
					*/

#include<bits/stdc++.h>
using namespace std;
int j=1;
string key,p;
string p1,p2,p3,p4;
string k1,k2,k3,k4,k5,k6,k7,k8,k[10000]="";
unsigned int a,b,c,d,e,f,g,h,i,jo,ko,l,m,n,x;
/* Function to change binary string to decimal value*/
unsigned int bin2dec(string str) {
	unsigned int N = 0;
	int size = str.length();
	int count = 0;
	int i=0;
	while(str[i]!='\0') {
	if ( str[i] == '1' )
	N = N + pow(2, size - count );
	count++;
	i++;
	}
	return N;
}
/* Function to change decimal to binary */
long long dec2bin(int N)
{
	int remainder;
	long binary = 0, i = 1;
	int count=0;
	while(N != 0) {
	remainder = N%2;
	N = N/2;
	binary= binary + (remainder*i);
	i = i*10;
	count++;
	}
	return binary;
}
/* One round of decryption with 6 keys */
void single_round(int i)
{

	a = (bin2dec(p1) * bin2dec(k[i])) % 65537;
	x = bin2dec(k[i]) ;

	b = (bin2dec(p2) + bin2dec(k[i+1])) % 65536;
	c = (bin2dec(p3) + bin2dec(k[i+2])) % 65536;
	d = (bin2dec(p4) % 65537 * bin2dec(k[i+3]) % 65537) % 65537;
	e = a ^ c;
	f = b ^ d;
	g = (e * bin2dec(k[i+4])) % 65537;
	h = (f * g) % 65537;
	i = (h * bin2dec(k[i+5])) % 65537;
	jo = (g + i) % 65536;
	ko = a ^ i;
	l = c ^ i;
	m = b ^ jo;
	n = d ^ jo;

	p1 = to_string(dec2bin(ko));
	while(p1.length()<16)
	{
		p1 = "0" + p1;
	}
	p2 = to_string(dec2bin(l));
	while(p2.length()<16)
	{
		p2 = "0" + p2;
	}
	p3 = to_string(dec2bin(m));
	while(p3.length()<16)
	{
		p3 = "0" + p3;
	}
	p4 = to_string(dec2bin(n));
	while(p4.length()<16)
	{
		p4 = "0" + p4;
	}
}
/* 8 keys generation in one round*/
void key_partition(int index)
{
	k[j] = "";
	string temp = "";
	for(int i=index;i<index + 16;i++)
	{
		temp = temp + key[i%128];
	}
	k[j] =  temp;
	j++;
	temp = "";
	for(int i=index + 16;i<index + 32;i++)
	{
		temp = temp + key[i%128];
	}
	k[j] =  temp;
	j++;
	temp = "";
	for(int i=index + 32;i<index + 48;i++)
	{
		temp = temp + key[i%128];
	}
	k[j] =  temp;
	j++;
	temp = "";
	for(int i=index + 48;i<index + 64;i++)
	{
		temp = temp + key[i%128];
	}
	k[j] =  temp;
	j++;
	temp = "";
	for(int i=index + 64;i<index + 80;i++)
	{
		temp = temp + key[i%128];
	}
	k[j] = temp;
	j++;
	temp = "";
	for(int i=index + 80;i<index + 96;i++)
	{
		temp = temp + key[i%128];
	}
	k[j] =  temp;
	j++;
	temp = "";
	for(int i=index + 96;i<index + 112;i++)
	{
		temp = temp + key[i%128];
	}
	k[j] =  temp;
	j++;
	temp = "";
	for(int i=index + 112;i<index + 128;i++)
	{
		temp = temp + key[i%128];
	}
	k[j] =  temp;
}
int main(void)
{
	int i;
	/* 128 bit key */
	key = "00101000001010100010101000101000011010010010100010101010001011000010110100101011000010010000100100101000001010000010101010101000";
	/* 64 bit Plain Text */
	p = "0101100101011011011100100101001111010001010100110111001101011011";
	cout << "Plain Text :" << endl;
	cout << p << endl;
	cout << "Key: " << endl;
	cout << key << endl;
	/* 4 partitions of plain text */
	p1 = "0101100101011011";
	p2 = "0111001001010011";
	p3 = "1101000101010011";
	p4 = "0111001101011011";
	/* 8 times key partitioning */
	key_partition(0);
	key_partition(25);
	key_partition(50);
	key_partition(75);
	key_partition(100);
	key_partition(125);
	key_partition(150);
	key_partition(175);
	/* 8 rounds */
	single_round(1);
	single_round(7);
	single_round(13);
	single_round(19);
	single_round(25);
	single_round(31);
	single_round(37);
	single_round(43);
	/* Appending 0 in the beggining of string if bits are less after the conversion to binary */
	while(p1.length()<16)
	{
		p1 = "0" + p1;
	}
	while(p2.length()<16)
	{
		p2 = "0" + p2;
	}
	while(p3.length()<16)
	{
		p3 = "0" + p3;
	}
	while(p4.length()<16)
	{
		p4 = "0" + p4;
	}
	cout << "Encrypted Text: " << endl;
	/* Last Round with 4 keys and printing the Encrypted Text*/
	cout << p1 << dec2bin(bin2dec(p2)) << dec2bin(bin2dec(p3)) << dec2bin(bin2dec(p4));
	dec2bin((bin2dec(p1) * bin2dec(k[49]))%65537) << dec2bin((bin2dec(p2) + bin2dec(k[50]))%65536) << dec2bin(bin2dec(p3) + bin2dec(
k[51])%65536) ;
	cout << endl;

}

