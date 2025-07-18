#include <iostream>
#include <string.h>
using namespace std;
string removeDuplicates(string s)
{
    string ans = "";
    int i = 0;
    while (i < s.length())
    {
        if (ans.length() > 0 && s[i] == ans[ans.length() - 1])
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}
string removeDuplicatesK(string s, int k)
{
    int i = 0;
    string ans = "";

    while (i < s.length())
    {
        int count = 1;
        // Start checking from the end of `ans`
        for (int j = ans.length() - 1; j >= 0 && ans[j] == s[i]; j--)
        {
            count++;
        }

        ans.push_back(s[i]);

        if (count == k)
        {
            for (int x = 0; x < k; x++)
            {
                ans.pop_back();
            }
        }

        i++;
    }

    return ans;
}

string removeOccurences(string s, string substr)
{
    while (s.find(substr) != string::npos)
    {
        s.erase(s.find(substr), substr.length());
    }
    return s;
}

bool checkPalindromeWithRemovalK(string s, int k)
{
    int i = 0;
    int count = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            if (count < k)
            {
                string s1 = s;
                s1.erase(i, 1);
                string s2 = s;
                s2.erase(j, 1);
                return checkPalindromeWithRemovalK(s1, k - 1) || checkPalindromeWithRemovalK(s2, k - 1);
            }
            else
            {
                return false;
            }
        }
        else
        {
            i++, j--;
        }
    }
    return true;
}

int expand(string s, int i, int j)
{
    int Icount = 0;
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        Icount++;
        i--;
        j++;
    }
    return Icount;
}
int countAllPosPalindrome(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // first odd k liye
        int oddKaAns = expand(s, i, i);
        // second even k liye
        int evenKaAns = expand(s, i, i + 1);
        // adding their count
        count = count + oddKaAns + evenKaAns;
    }
    return count;
}

int main()
{
    string s1;
    getline(cin, s1);
    // cout <<"string is : "<<name<<endl;

    // string also has various predefined built in functions
    // are written in the note book

    // // question 1 - remove adjacent duplicates
    // string result = removeDuplicates(s1);
    // cout << "after removing adjacent duplicates : " << result << endl;

    // // question 2 - removing adjacent duplicates that are coming k times in adjacent
    // //  example : s="aabbbabbbnnc" and k=3 , output = "nnc"
    // int k = 3;
    // string result = removeDuplicatesK(s1, k);
    // cout << "after removing k adjacent duplicates : " << result << endl;

    // // question -3 , remove all occurences of a substring
    // string substr="abc";
    // string result = removeOccurences(s1, substr);
    // cout << "after removing all Occurences : " << result << endl;

    // // question 4 - check valid palindrome after k removal of char also
    // int k = 2;
    // if (checkPalindromeWithRemovalK(s1, k))
    // {
    //     cout << "valid palindrome for us " << endl;
    // }
    // else
    // {
    //     cout << "not a valid palindrome for us " << endl;
    // }

    // question 5- count the total number of all possible palindrome substrings in a given substring
    int Pcount = countAllPosPalindrome(s1);
    cout << "total possible palindrome substring in the string is : " << Pcount << endl;
}