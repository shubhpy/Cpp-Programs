// C program for implementation of KMP pattern searching
// algorithm
#include<iostream>

using namespace std;

void computeLPSArray(string pat, int M, int *lps);

void computeLPSArray(string pat, int M, int *lps)
{
	int len = 0; // length of the previous longest prefix suffix
	int i;

	lps[0] = 0; // lps[0] is always 0
	i = 1;

	// the loop calculates lps[i] for i = 1 to M-1
	while (i < M)
	{
	if (pat[i] == pat[len])
	{
		len++;
		lps[i] = len;
		i++;
	}
	else // (pat[i] != pat[len])
	{
		if (len != 0)
		{
		// This is tricky. Consider the example
		// AAACAAAA and i = 7.
		len = lps[len-1];

		// Also, note that we do not increment i here
		}
		else // if (len == 0)
		{
		lps[i] = 0;
		i++;
		}
	}
	}

	for(int i=0;i<M;i++){
	    cout << lps[i] << " ";
	}
}

// Driver program to test above function
int main()
{
    string pat = "AABBZ";
	int *lps = (int *)malloc(sizeof(int)*pat.length());
	int j = 0; // index for pat[]

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, pat.length(), lps);
return 0;
}
