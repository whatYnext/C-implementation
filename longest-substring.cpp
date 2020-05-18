// longest-substring.cpp : find the longest substring without repeating
// for example 
// "aaaaa" return 1;
// "ababsbs", return 3; 
// "wserna", return 6;


// Variable settings:
// i is left position, j is the right position, j1 is the middle variable, k is the moving variable
// length is returned maximum length of substring

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int longestsubstring(string &S)
{
	int length = 1; int i = 0; int j,j1=1,k; 
	while (i<S.size())                // outer loop: move the beginning character
	{
		j = j1;
		for (j; j < S.size(); j++)              // inner loop: compare all characters from the current beginning character to the end
		{
			k = i;
			while (k < j)
			{
				if (S[j] == S[k])             // if current character is equal to some previous characters, then compare the current	                                      
										
			    {
					j1 = j;  // store the right position
					i = k+1; // store the left position
					if (j-i>length)
						length = j - i;
					break;
				}
				k++;
			}
			if (k < j)                                    // if some character is found to be equal to the current character, then just break inner loop
				break;
			if (k==j&&k- i + 1> length)                   // if there is no same value found and current length is larger than stored maximum length, we store.
				length = k - i + 1;		
		}
		if (j == S.size())
			break;
	}
	return length;
}
int guess(string &S, int x)                          // if the user's guess is right, then return 1; else, return 0
{
	if (longestsubstring(S) == x)
		return 1;
	else
		return 0;
}
int main()
{
	string s1 = "aaaaaa", s2="abababab",s3="qwertyuioyasdfghj";
	cout << guess(s1, 1) <<endl;
	cout << guess(s2, 2) << endl;
	cout << guess(s3, 11) << endl;
    return 0;
}

