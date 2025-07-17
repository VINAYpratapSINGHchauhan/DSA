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

    // question 2 - removing adjacent duplicates that are coming k times in adjacent
    //  example : s="aabbbabbbnnc" and k=3 , output = "nnc"
    int k = 3;
    string result = removeDuplicatesK(s1, k);
    cout << "after removing k adjacent duplicates : " << result << endl;
}