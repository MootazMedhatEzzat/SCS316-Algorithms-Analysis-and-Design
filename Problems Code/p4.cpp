/*
  • By Applying Dynamic Programming In This Problem The Time Complexity reduced
    From O(N^3) to O(N^2) By Storing Results Of SubProblems.

  • N -> Length Of The Given String.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to print the longest palindromic substring lps[sIndex..eIndex].
void printLPS( string, int, int, int);

// Function to get the longest palindrome substring the length of it.
void longestPalindromicSubstring(string);

int main()
{
	string s = "cbbd";
	//string s = "cboobd";
	cout << "Input: " << endl;
	cout << "s = " << s << endl << endl;
	longestPalindromicSubstring(s);
	return 0;
}

void longestPalindromicSubstring(string str)
{
    // To store the length of given string(str).
	int stringLength = str.size();

	// To keep track the length of the longest palindrome substring and it's start.
	int maxSubStringLength = 1, start = 0;

	// This table will be false if the input string(str[i..j]) is not palindrome,
	// Else table[i][j] will be true.
	bool table[stringLength][stringLength];

	// Initialize the table with false.
	for(int i = 0; i < stringLength; i++)
    {
        for (int j = 0; j < stringLength; j++)
        {
            table[i][j] = false;
        }
    }

    // If the reverse of that string is the same as the original string,
    // then there is no need to check for the rest of conditions.
    if ((stringLength % 2) != 0)
    {
        int counter = 0;
        for (int i = 0; i < ((stringLength - 1) / 2); i++)
        {
            if (str[i] == str[stringLength - 1 - i])
            {
                counter++;
            }
        }
        if (counter == ((stringLength - 1) / 2))
        {
            printLPS(str, 0, (stringLength - 1), stringLength);
            cout << str << " Is Called A Palindrome String Because The Reverse Of That String Is The Same As The Original." << endl;
            exit(0);
        }
    }

    // Because all substrings of length 1 are actually palindromes.
	for (int i = 0; i < stringLength; i++)
    {
        table[i][i] = true;
    }

	// Then we will check for sub-string of length 2.
	for (int i = 0; i < stringLength - 1; i++)
    {
		if (str[i] == str[i + 1])
		{
			table[i][i + 1] = true;
			start = i;
			maxSubStringLength = 2;
		}
	}

	// Then we will check for sub-string of length that greater than 2.
	for (int subStringLength = 3; subStringLength <= stringLength; subStringLength++)
    {
		for (int i = 0; i < subStringLength - subStringLength + 1; i++)
        {

			// To keep track the ending index of substring from starting index i and length subStringLength
			int j = i + subStringLength - 1;

			if (table[i + 1][j - 1] && str[i] == str[j])
            {
				table[i][j] = true;

				if (subStringLength > maxSubStringLength)
                {
					start = i;
					maxSubStringLength = subStringLength;
				}
			}
		}
	}

	printLPS(str, start, start + maxSubStringLength - 1, maxSubStringLength);
}

void printLPS( string lps, int sIndex, int eIndex, int lpsLength)
{
    cout << "Output: ";
	for (int i = sIndex; i <= eIndex; i++)
    {
        cout << lps[i];
    }
    cout << endl;
    cout << "Length is: " << lpsLength << endl;
}
