/* Author: Syed Alfran Ali */

// Cracking Monoalphabetic Caesar cipher

#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int main(void)
{
        int n,i,temp,lastIndex,temp2;
	// Time variable to take cpu time for srand . i.e. generating random function seeds.
	time_t t;
	// Store array to check weather same used mapping with key is used if same character appears.
        int store[30];
        int key[26]={0};
	// Random string which can be cracked of n<=4
        char deCrypted[100] = "iiit";
	// Change n if characters of the above string are changed
	n = 4;
	// Array to map each alphabet to another
	char keY[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	// For swaping the index and than decreasing it to solve it in O(1).
	lastIndex = 25;
	// Initialising the store array to 0.
        for(i=0;i<=25;i++)
        {
                store[i] = 0;
        }
	// Initialising the seeds for random function call.
	srand((unsigned) time(&t));
        char enCrypted[n+1];
	char newDec[n+1];
        for(i=0;i<n;i++)
        {
         	/* Handling for spaces */
                if(deCrypted[i]==' ')
                {
		         enCrypted[i] = ' ';
		         continue;
                }
		/* Handling for special Characters like #@$.. */
		if(deCrypted[i]>'z' || deCrypted[i]<'a')
		{
			enCrypted[i] = deCrypted[i];
			continue;
		}
		/* If alphabets are in range of a to z */
                if(deCrypted[i]<='z' && deCrypted[i]>='a')
                {
			/* Checking if character is mapped earlier already */
                        if(store[deCrypted[i]-'a']==0)
                        {

				temp = rand()%(lastIndex + 1);
				/* Generating a random number */
                                enCrypted[i] = keY[temp];
				/* Swapping the assigned alphabet of key with the last alphabet
					 and then decreasing the lastIndex to do it in O(1).*/
				temp2 = keY[lastIndex];
				keY[lastIndex] = keY[temp];
				keY[temp] =  temp2;
				lastIndex--;
				/* Storing the value if same character comes again */
                                key[deCrypted[i] - 97] = enCrypted[i];
				store[deCrypted[i] - 97]=1;
                        }
			/* If character is already assigned its respective crypted value */
                        else
                        {
                                enCrypted[i] =  key[deCrypted[i]- 97];
                        }
                }
        }
	/* Printing the Encrypted Text */
	cout << "Encypted Text" << endl;
        for(i=0;i<n;i++)
        {
              cout << enCrypted[i];
        }
        cout << endl;
	/* Decryption Begins */
	// Checking array of all combinations
	char combination[5];
	int index = 0;
	int matched = 0;
	/* Checking for first character */
	for(char i='a';i<='z';i++)
	{
		combination[index] = i;
		n--;
		if(n == 0)
		{
			// Putting last char to null for string comparison
			combination[index+1] = '\0';
			if(strcmp(combination,deCrypted) == 0)
			{
				matched = 1;
			}
			if(matched == 0)
			{
				n++;
				continue;
			}
			break;
		}
		index++;
		/* Checking for last third character*/
		for(char j='a';j<='z';j++)
		{
			combination[index] = j;
			n--;
			if(n == 0)
			{
				combination[index+1] = '\0';
				if(strcmp(combination,deCrypted) == 0)
				{
					matched = 1;
				}
				if(matched == 0)
				{
					n++;
					continue;
				}
				break;
			}
			index++;
			/* Checking for last second character*/
			for(char k='a';k<='z';k++)
			{
				combination[index] = k;
				n--;
				if(n == 0)
				{
					combination[index+1] = '\0';
					if(strcmp(combination,deCrypted) == 0)
					{
						matched = 1;
					}
					if(matched == 0)
					{
						n++;
						continue;
					}
					break;
				}
				index++;
				/* Checking for last character */
				for(char l='a';l<='z';l++)
				{
					combination[index] = l;
					n--;
					if(n == 0)
					{
						combination[index+1] = '\0';
						if(strcmp(combination,deCrypted) == 0)
						{
							matched = 1;
						}
						if(matched == 0)
						{
							n++;
							continue;
						}
						break;
					}
				}
				if(matched == 1) break;
				index--;
				n++;
			}
			if(matched == 1) break;
			index--;
			n++;
		}
		if(matched == 1) break;
		index--;
		/* Increasing the length back to initial */
		n++;
	}
	/* Printing the Decrypted Text */
	cout << "Decrypted Text" << endl;
        printf("%s\n",combination);

}

