/*
	Author: Syed Afran Ali
 		--- DES Encryption */

/* Key Terms Used :
	K56 = 56 bit Key
	K48 = 48 bit Key
	ORM = Old Right Message
	OLM = Old Left Message
	NLM = New Left Message
	NRM = New Right Message
	ORK = Old Right Key
	OLK = Old Left Key
	NLK = New Left Key
	NRK = New Right Key
	enCrypted = Final Encrypted Message
	xor_of_48() = 48 bit key xor with 48 bit P.T.
	compress() = 56 bit to 48 bit Conversion
	Rest all are self explainatory */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/* Assigning values in matrix to be used later */
int key_permu1[]   =    {57, 49,  41, 33,  25,  17,  9,
			 1, 58,  50, 42,  34,  26, 18,
			10,  2,  59, 51,  43,  35, 27,
			19, 11,   3, 60,  52,  44, 36,
			63, 55,  47, 39,  31,  23, 15,
			 7, 62,  54, 46,  38,  30, 22,
			14,  6,  61, 53,  45,  37, 29,
		         21, 13, 5, 28, 20, 12, 4};

int key_permu2[]    = 	{14, 17, 11, 24,  1,  5,
			 3, 28, 15,  6, 21, 10,
			23, 19, 12,  4, 26,  8,
			16,  7, 27, 20, 13,  2,
			41, 52, 31, 37, 47, 55,
			30, 40, 51, 45, 33, 48,
			44, 49, 39, 56, 34, 53,
		        46, 42, 50, 36, 29, 32};


int initial_permu_message[] = 	{58, 50, 42, 34, 26, 18, 10, 2,
				60, 52, 44, 36, 28, 20, 12, 4,
				62, 54, 46, 38, 30, 22, 14, 6,
				64, 56, 48, 40, 32, 24, 16, 8,
				57, 49, 41, 33, 25, 17,  9, 1,
				59, 51, 43, 35, 27, 19, 11, 3,
				61, 53, 45, 37, 29, 21, 13, 5,
				63, 55, 47, 39, 31, 23, 15, 7};

int final_permu_message[] = 	{40,  8, 48, 16, 56, 24, 64, 32,
				39,  7, 47, 15, 55, 23, 63, 31,
				38,  6, 46, 14, 54, 22, 62, 30,
				37,  5, 45, 13, 53, 21, 61, 29,
				36,  4, 44, 12, 52, 20, 60, 28,
				35,  3, 43, 11, 51, 19, 59, 27,
				34,  2, 42, 10, 50, 18, 58, 26,
				33,  1, 41,  9, 49, 17, 57, 25};

int right_permu_message[] =     {16,  7, 20, 21,
				29, 12, 28, 17,
				 1, 15, 23, 26,
				 5, 18, 31, 10,
				 2,  8, 24, 14,
				32, 27,  3,  9,
				19, 13, 30,  6,
		            	22, 11, 4, 25};

int message_exp[] = 	{32, 1,  2,  3,  4,  5,
			 4,  5,  6,  7,  8,  9,
			 8,  9, 10, 11, 12, 13,
			12, 13, 14, 15, 16, 17,
			16, 17, 18, 19, 20, 21,
			20, 21, 22, 23, 24, 25,
			24, 25, 26, 27, 28, 29,
		    	28, 29, 30, 31, 32, 1};


int key_shift[] = {1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int s1[4][16] = {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
		 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
		 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
		15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13};

int s2[4][16] = {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
		 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
		 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
		13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9};

int s3[4][16] = {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
		13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
		13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
		 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12};

int s4[4][16] = { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
		13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
		10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
		 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14};

int s5[4][16] = { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
		14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
		 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
		11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3};

int s6[4][16] = {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
		10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
		 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
		 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13};

int s7[4][16] = {4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
		13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
		 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
		 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12};
int s8[4][16] = {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
		 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
		 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
                 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

/* Message to be encrypted */
char message[] ={"0101011100100101010001110110011110101010101010110100010110101110"};
/* Key used to encrypt the message */
char key[]={"0101101000110100010100110111101110011001101111001101011101110100"};

char enCrypted[64];
char ORM[32],OLM[32],ORK[28],OLK[28],temp_ORM[32];
char NRM[32],NLM[32],NRK[28],NLK[28];
char temp[64],K56[56],K48[48],RM_48[48];
int endbits,midbits;

int dec2bin(int n)
{
    int dec, remain, base = 1, bin = 0, ones = 0;
    dec = n;
    while (n > 0)
    {
        remain = n % 2;
        bin = bin + remain * base;
        n = n / 2;
        base = base * 10;
    }
    return bin;
}
int bin2dec(int endbits)
{
    int bin, dec = 0, base = 1, remain;
    bin = endbits;
    while (endbits > 0)
    {
        remain = endbits % 10;
        dec = dec + remain * base;
        endbits = endbits / 10 ;
        base = base * 2;
    }
    return dec;
}

void InDex(int a)
{
    int i,flag1=0,factor=10000;
    char temp[6];
    for(i=a;i<a+6;i++)
    {
        temp[flag1] = RM_48[i];
        flag1++;
    }
    endbits=((temp[0] -'0')*10)+(temp[5] - '0');
    midbits = ((temp[1]-'0')*1000)+((temp[2]-'0')*100)+((temp[3]-'0')*10)+(temp[4]-'0');
    endbits=bin2dec(endbits);
    midbits = bin2dec(midbits);
}

void fiNal(int i,int bin)
{
    int n,factor = 10000;
     n=i+4;
    while((i<n) && (factor>1))
    {
      factor = factor/10;
      temp_ORM[i] = (bin/factor) + '0';
      bin = bin % factor;
      i++;
    }

}
void sbox()
{
    int i=0,a=0,n,bin,flag1;
    InDex(0);
    n = s1[endbits][midbits];
    bin = dec2bin(n);
    fiNal(0,bin);

    a=6;
    InDex(a);
    n = s2[endbits][midbits];
    bin = dec2bin(n);
    fiNal(4,bin);

    a=12;
    InDex(a);
    n = s3[endbits][midbits];
    bin = dec2bin(n);
    fiNal(8,bin);

    a=18;
    InDex(a);
    n = s4[endbits][midbits];
    bin = dec2bin(n);
    fiNal(12,bin);

    a=24;
    InDex(a);
    n = s5[endbits][midbits];
    bin = dec2bin(n);
    fiNal(16,bin);

    a=30;
    InDex(a);
    n = s6[endbits][midbits];
    bin = dec2bin(n);
    fiNal(20,bin);

    a=36;
    InDex(a);
    n = s7[endbits][midbits];
    bin = dec2bin(n);
    fiNal(24,bin);

    a=42;
    InDex(a);
    n = s8[endbits][midbits];
    bin = dec2bin(n);
    fiNal(28,bin);
    for(i=0;i<32;i++)
    {
       ORM[i]=temp_ORM[i];

    }
    ORM[i] = '\0';
}

/* Store the values of sbox operation in ORM */
void sbox_later()
{
    int i;
    char temp[32];
    for(i=0;i<32;i++)
    {
        temp[i] = ORM[right_permu_message[i]-1];

    }
    for(i=0;i<32;i++)
    {
        ORM[i]=temp[i];
    }
}
/* Perform the Shift operation */
void Lshift()
{
    int i,j,flag1=0,flag2=0;
    /* Right Shift */
    for(j=1;j<28;j++)
    {
        NRK[flag2++]=ORK[j];
    }
    NRK[flag2++] = ORK[0];
    NRK[flag2] = '\0';
    /* Left Shift */
    for(i=1;i<28;i++)
    {
        NLK[flag1++]=OLK[i];

    }
    NLK[flag1++] = OLK[0];
    NLK[flag1] = '\0';
    for(j=0;j<28;j++)
    {
       ORK[j]=NRK[j];
    }
    for(i=0;i<28;i++)
    {
       OLK[i]=NLK[i];
    }
}
/* Convert 56 bits to 48 bits */
void compress()
{
    int i,left=0,right=0,flag1=0;
     for(i=0;i<56;i++)
     {
         if(i<28)
        {
            K56[i]=NLK[left];
            left++;
        }
        else
        {
            K56[i]=NRK[right];
            right++;
        }
     }
    for(i=0;i<56,flag1<48;i++)
    {
        K48[flag1] = K56[key_permu2[i]-1];
        flag1++;

    }
}

/* Use left shift function to shift the key bits and than convert 56 bits to 48 */
void key_rotation(int round_n)
{
    int i;
    int n  = key_shift[round_n];
    for(i=1;i<=n;i++)
    {
        Lshift();
    }

    compress();
}

/* Perform xor operation of 48 but key and 48 bit message */
void xor_of_48()
{
    int i;
    for(i=0;i<48;i++)
    {
        if((K48[i]=='0' && RM_48[i]=='0') || (K48[i]=='1' && RM_48[i]=='1'))
            RM_48[i] = '0';
        else
            RM_48[i] = '1';
    }
}

/* Getting new right message */
void old_LR_xor()
{
    int i;
    for(i=0;i<32;i++)
    {
        if((ORM[i]=='0' && OLM[i]=='0') || (ORM[i]=='1' && OLM[i]=='1'))
            NRM[i] = '0';
        else
            NRM[i] = '1';
    }
    NRM[i] = '\0';

}

/* Performing round operations and after s box printing the message */
void message_rotation()
{
	int i,flag1=0;
	for(i=0;i<32;i++)
	{
		NLM[i]=ORM[i];
	}
	for(i=0;i<48;i++)
	{
		RM_48[i] = ORM[message_exp[i]-1];
	}
	compress();
	sbox();
	sbox_later();
	old_LR_xor();
	for(flag1=0;flag1<32;flag1++)
	{
		OLM[flag1] = NLM[flag1];
		ORM[flag1] = NRM[flag1];
	}
	OLM[flag1] = '\0';
	ORM[flag1] = '\0';
	printf("\n%s\n%s\n",OLM,ORM);
}


int main(void){
	int i,left=0,right=0;
	for(i=0;i<64;i++)
	{
		temp[i] = message[initial_permu_message[i]-1];
	}
	for(i=0;i<64;i++)
	{
		message[i]=temp[i];
	}
	for(i=0;i<64;i++)
	{
		if(i<32)
		{
		    OLM[left] = message[i];
		    left++;
		}
		else
		{
		    ORM[right] = message[i];
		    right++;
		}
	}
	OLM[left] = '\0';
	ORM[right] = '\0';
	int flag1=0;
	for(i=0;i<64,flag1<56;i++)
	{
		K56[flag1] = key[key_permu1[i]-1];
		flag1++;
	}
	left=0,right=0;
	for(i=0;i<56;i++)
	{
		if(i<28)
		{
		    OLK[left] = K56[i];
		    left++;
		}
		else
		{
		    ORK[right] = K56[i];
		    right++;
		}
	}
	for(i=0;i<=15;i++)
	{
		printf("\nAfter round %d:\n",i);
		key_rotation(i);
		message_rotation();
	}
	left=0,right=0;
	for(i=0;i<64;i++)
	{
		if(i<32)
		{
		    message[i] = ORM[left];
		    left++;
		}
		else
		{
		    message[i]=OLM[right];
		    right++;
		}
	}
	message[i]='\0';

	/* Reverse Permutation */
	for(i=0;i<64;i++)
	{
	enCrypted[i] = message[final_permu_message[i]-1];
	}
	enCrypted[i]='\0';
	printf("\nEncrypted Plain text\n%s\n",enCrypted);
}

