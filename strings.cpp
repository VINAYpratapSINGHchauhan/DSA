#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

string decodeTheString(string key, string message)
{
    // create the mapping
    char start = 'a';
    char map[280] = {0};
    for (auto ch : key)
    {
        if (ch != ' ' && map[ch] == 0)
        {
            map[ch] = start;
            start++;
        }
    }

    // use the mapping
    string ans;
    for (auto ch : message)
    {
        if (ch == ' ')
        {
            ans.push_back(' ');
        }
        else
        {
            char decodedValue = map[ch];
            ans.push_back(decodedValue);
        }
    }

    return ans;
}

int findMinimumTimeToCollectGArbage(vector<string> &garbage, vector<int> &travel)
{
    int pickTimeP = 0; // 1-2-3-4
    int pickTimeM = 0; // 1-2-3
    int pickTimeG = 0; // 1-2-3

    int lastIndexP = 0; // 0-0-1-3
    int lastIndexM = 0; // 1-2
    int lastIndexG = 0; // 0-1-2

    int travelTimeP = 0;
    int travelTimeM = 0;
    int travelTimeG = 0;

    for (int i = 0; i < garbage.size(); i++)
    {
        string str = garbage[i];
        for (auto ch : str)
        {
            if (ch == 'P')
            {
                pickTimeP++;
                lastIndexP = i;
            }
            else if (ch == 'G')
            {
                pickTimeG++;
                lastIndexG = i;
            }
            else if (ch == 'M')
            {
                pickTimeM++;
                lastIndexM = i;
            }
        }
    }

    for (int i = 0; i < lastIndexP; i++)
    {
        travelTimeP += travel[i];
    }
    for (int i = 0; i < lastIndexM; i++)
    {
        travelTimeM += travel[i];
    }
    for (int i = 0; i < lastIndexG; i++)
    {
        travelTimeG += travel[i];
    }

    return (pickTimeP + pickTimeM + pickTimeG) + (travelTimeP + travelTimeM + travelTimeG);
}

string customSortSorting(string order, string str)
{
    unordered_map<char, int> priority;
    for (int i = 0; i < order.length(); ++i)
    {
        priority[order[i]] = i;
    }
    sort(str.begin(), str.end(), [&](char a, char b)
         { return priority[a] < priority[b]; });
    return str;
}

string createMapping(string & str)
{
    // create mapping 
    char start = 'a';
    char map[300] = {0};
    for (auto ch : str)
    {
        if (map[ch] == 0)
        {
            map[ch] = start;
            start++;
        }
    }
    //update the string with mapped value
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        str[i]=map[ch];
    }
    return str;
}
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{   
    vector<string> ans;
    createMapping(pattern);
    for(auto str:words){
        string originalStr=str;
        createMapping(str);
        if(str==pattern){
            ans.push_back(originalStr);
        }
    }
    return ans;
}

int main()
{
    string s1;
    cout << "enter string s1 : ";
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
    // int Pcount = countAllPosPalindrome(s1);
    // cout << "total possible palindrome substring in the string is : " << Pcount << endl;

    // //  question 6- decode the message i.e you are given with the key and by the key u do the mapping (mapping of one character cannot be done again ) after mapping you make the substiution table (col 1- key character , col 2- mapped value ) and with the help of substitution table you decode the input message and output the decoded value
    // string key = "the quick brown fox jumps over the lazy dog";
    // string message = "vkbs bs t suepuv";
    // string result = decodeTheString(key, message);
    // cout << "decoded message is : " << result << endl;

    // // question 7 -find minimum amount of time to collect the garbage from the garbage vector string and the travel time indicatign string vector
    // vector<string> garbage = {"PPG","GMP","MMG","P"};
    // vector<int> travel = {2, 4, 3};
    // int result = findMinimumTimeToCollectGArbage(garbage, travel);
    // cout << "minimum time to collect garbage is : " << result << endl;

    // // question 8 (791 in lc) - custom sort sorting , sorting a given string on the basis of order of second string given with
    // string order = "cba";
    // string str = "abcd";
    // string sortedStr = customSortSorting(order, str);
    // cout << "sorted str string : " << sortedStr << endl;

    // // question 9 (890 in lc) - find and replace pattern ,  given  a list of strings 'words' and a string 'pattern' and  returns a list of strings of words[i] that matches the pattern
    // vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    // string pattern = "abb";
    // vector<string> result = findAndReplacePattern(words, pattern);
    // for (auto e : result)
    // {
    //     cout << e << " ";
    // }
} 