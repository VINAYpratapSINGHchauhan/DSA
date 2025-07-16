#include <iostream>
#include <string.h>
using namespace std;
int findLength (char ch[],int size){
    // int length=strlen(ch);     //this is predefined funciton of calculating length
   int length=0;
    while(ch[length]!='\0'){
    length++;
   }
   return length;
}
int main()
{
    // char arrays
    char chArray[100];
    // // input directly
    cout << "enter char array : ";
    cin >> chArray;
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

    // printing the length of the char array
    int len =findLength(chArray,100);
    cout<<"length of the char arry is : "<<len<<endl;
}
