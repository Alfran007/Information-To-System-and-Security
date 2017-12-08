/*
	Author: Syed Alfran Ali
            --- R.S.A Implementation     */


#include<bits/stdc++.h>
using namespace std;
/* Function to get power of any large number and takes modulus with the thirs parameter while calculating the power*/
unsigned long long int pow(unsigned long long int x, unsigned long long int y,unsigned long long int p)
{
    unsigned long long int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
/* Function to get greatest common divisor*/
unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int main(void)
{
	stringstream stream1;
	unsigned long long int p,q;
	/* Array from which random prime number values of p and q will be picked */
	unsigned long long int random[] = {
	83,     89,     97,    101,    103,    107,    109,    113,
        127,    131,    137,    139,    149,    151,    157,    163,    167,    173,
        179,    181,    191,    193,    197,    199,    211,    223,    227,    229,
        233,    239,    241,    251,    257,    263,    269,    271,    277,    281,
        283,    293,    307,    311,    313,    317,    331,    337,    347,    349,
        353,    359,    367,    373,    379,    383,    389,    397,    401,    409,
        419,    421,    431,    433,    439,    443,    449,    457,    461,    463,
        467,    479,    487,    491,    499,    503,    509,    521,    523,    541,
        547,    557,    563,    569,    571,    577,    587,    593,    599,    601,
        607,    613,    617,    619,    631,    641,    643,    647,    653,    659,
        661,    673,    677,    683,    691,    701,    709,    719,    727,    733,
        739,    743,    751,    757,    761,    769,    773,    787,    797,    809,
        811,    821,    823,    827,    829,    839,    853,    857,    859,    863,
        877,    881,    883,    887,    907,    911,    919,    929,    937,    941,
        947,    953,    967,    971,    977,    983,    991,    997
	};
	/* Generate random numbers as index which points to some prime value in above array */
	p = random[rand()%145];
	q = random[rand()%145];
	/* Calculating product of p and q in n */
	unsigned long long int n = p*q;
	/* Calculating totient function(psi) = (p-1)*(q-1) */
	unsigned long long int totient = (p-1)*(q-1);
	/* Generating random number less than totient */
	unsigned long long int e = fmod(rand(),totient);
	/* Checking that e is coprime with totient if not than increment e which is not coprime*/
	while(gcd(e,totient)!=1)
	{
		e++;
	}
	unsigned long long int d;
	/* Getting value of D such that (D X E)%((p-1)*(q-1)) = 1 */
	for(int i=2;i<totient;i++)
	{
		if(fmod((i*e),totient)==1)
		{
			d = i;
			break;
		}
	}
	/* Enter any integer number */
	cout << "Enter the number to decrypt, say 10:" << endl;
	unsigned long long int pt;
	cin >> pt;
	cout << "Plain Text before Encryption" << endl;
	/* Power function to get power while taking modulus */
	unsigned long long int ct = pow(pt,e,n);
	/* Encrypted Text*/
	printf("Encrypted data = %llu\n", ct);
	unsigned long long int m = pow(ct, d,n);
	/* Plain Text After Decryption */
   	printf("Plain Text after Decryption: %llu\n",m);
}

