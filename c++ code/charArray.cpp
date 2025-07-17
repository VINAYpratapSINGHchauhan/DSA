#include <iostream>
#include <string.h>
using namespace std;
int findLength(char ch[], int size)
{
    // int length=strlen(ch);     //this is predefined funciton of calculating length
    int length = 0;
    while (ch[length] != '\0')
    {
        length++;
    }
    return length;
}
void printUpperCase(char ch[], int size)
{
    int i = 0;
    while (ch[i] != '\0')
    {
        // check if the character is lower case
        if (ch[i] >= 'a' && ch[i] <= 'z')
        {
            ch[i] = ch[i] - 'a' + 'A';
        }
        i++;
    }
    cout << "after upper case operation : " << ch << endl;
}
void replacewithSpace(char ch[], int size)
{
    int i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] == '@')
        {
            ch[i] = ' ';
        }
        i++;
    }
}
bool checkPalindrome(char ch[], int length)
{
    int i = 0;
    int j = length - 1;
    while(i<=j){
        if(ch[i]!=ch[j]){
            return false;
        }
        i++ , j--;
    }
    return true;
}
int main()
{
    // char arrays
    char chArray[100];
    // // input directly
    cout << "enter char array we are getting input in cin.getline : ";
    // cin >> chArray;
    cin.getline(chArray, 100);
    // // output directly
    // cout << "value of char array : " << chArray<<endl;

    // // string in array ends with a null character '\o' which indicates the terminatiin of the string
    // // assuming input=vina but our char has 8 memory block then null character will be at end that s 4th index

    // char nullChar = chArray[4];
    // // printing the ascii value of the null character
    // int value = (int)nullChar;
    // cout<<"printing the null character : "<<nullChar<<endl;
    // cout << "printing the ascii value of the null character : " << value << endl;

    // // finding but will be in the string after null character
    // char charAfterNUll = chArray[5];
    // cout<<"printing the character after null : "<<charAfterNUll<<endl;
    // // printing the ascii value of the null character
    // int value2 = (int)charAfterNUll;
    // cout << "printing the ascii value of the charAfterNUll : " << value2 << endl;

    // // getting string as a input that contains tab or spaces
    // cout<<"give input again containing delimitor except enter i.e new line character: "<<endl;
    // cin.getline(chArray,100);
    // cout<<"char array with spaces or tab that are called delimitor : "<<endl;
    // cout<<chArray<<endl;

    // // printing the length of the char array
    int len = findLength(chArray, 100);
    // cout << "length of the char arry is : " << len << endl;

    // reverse the char array
    // same code using two pointer approach see in copy
    // utility function = reverse(chArray,chArray+len);

    // // convert to upper case
    // printUpperCase(chArray, 100);

    // // replace @ with ' '(space)
    // replacewithSpace(chArray, 100);
    // cout << chArray << endl;

    // check palindrome
    if (checkPalindrome(chArray, len))
    {
        cout << "valid palindrome" << endl;
    }
    else
    {
        cout << "not a valid palindrome" << endl;
    }

     
}
