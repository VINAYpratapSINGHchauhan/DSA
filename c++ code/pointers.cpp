#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
int main()
{

    // creation of a pointer

    //  int a=5;
    //  cout<<"a : "<<a<<endl;
    //  cout<<"address of a : "<<&a<<endl;
    //  int * ptr =&a;
    //  cout<<"ptr : "<<ptr<<endl;
    //  cout<<"value at ptr : "<<*ptr<<endl;
    //  cout<<"address of ptr : "<<&ptr<<endl;
    //  cout<<"size of integer pointer ptr : "<<sizeof(ptr)<<endl;
    //  cout<<"type of integer pointer ptr : "<<typeid(ptr).name()<<endl;

    //  char ch='k';
    //  char * chptr=&ch;
    //  cout<<"size of character pointer chptr : "<<sizeof(ptr)<<endl;
    //  cout<<"type of character pointer chptr : "<<typeid(chptr).name()<<endl;

    //  declaratioon of  pointer

    // 1. bad practise for declaration of pointer
    // int *newPtr;             // it will store here any random adrress in memory
    // cout << newPtr << endl;  // give that adrress as output
    // cout << *newPtr << endl; // give a value of illegal address as it will store here any random adrress in memory
    // 2. good practise - NULL POINTER
    // int *newPtr=0;           // it will store 0 here
    // cout << newPtr << endl;  // 0 output
    // cout << *newPtr << endl; //program will terrminate do not show any thing here runtime error


// char array pointer and integer array pointer behave differently see in the copy
//imp for MCQ see in the copy for more info

// int *ptr=&arr;  this will give error wrong syntax

//very confusing point of pointer :

// 1. this is a pointer to an  whole array 
int arr[5]={10,20,30,40,50};
int (*ptr)[5]=&arr;
//access element like 
cout<<(*ptr)[0]<<" "<< (*ptr)[4]<<endl;

// 2. this is a array of pointer of size 5 names ptr1
int a=10, b=20, c=30;
int * ptr1[3]={&a,&b,&c};
cout<<&a<<endl; //this is equal to ptr1[0]
//access element like 
cout<<ptr1[0]<<" "<<*ptr1[0]<<" "<< ptr1[1]<<endl;

 

}
