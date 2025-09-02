#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
private:
    string gf;

public:
    int id;  // property 1
    int age; // property 2 , similary niche b hai...
    bool present = 0;
    string name;

    Student(int _id, string _name, int age, string gfname)
    {
        id = _id;
        name = _name;
        this->age = age;
        gf = gfname;
        cout << "parameterized ctor student is " << name << " age is " << age << " and id is " << id << " and gf is " << gf << endl;
    }

    // copy constructure
    Student(const Student &srcobj) //const likha gya hai taki srcobj meo koi chnage na ho by refrence pass hua h kyuki hm hm hi copy bna rhe hai 
    { 
        cout<<"student copy constructure is called"<<endl;
        this->name=srcobj.name;
        this->id=srcobj.id;
        this->gf=srcobj.gf;
        this->age=srcobj.age;
    }

    Student()
    {
        cout << "constructor with no parameter is called" << endl;
    }

    void study()
    { // behaviour 1
        cout << name << " is studying." << endl;
    };
    void sleep()
    { // behaviour 2
        cout << name << " is sleeping." << endl;
    };
    void bunk()
    { // behaviour 3
        cout << name << " is bunking." << endl;
    };

private:
    void chatting()
    {
        cout << "chatting with " << gf << endl;
    }
};
int main()
{
    //     vector<int> arr;
    //     cout<<sizeof(arr);
    //    string name;
    //    cout<<sizeof(name);

    Student s1(01, "vinay", 21, "aditya");
    cout << s1.name << endl;
    // Student s2;
    // Student s3;                // this is created on stack memory - static allocation
    // Student *s4 = new Student; // this is created on heap memory - dynamic allocation
    // Student *s5 = new Student(05, "chintu", 23, "priya");
    // cout << s5->name << endl; // accesing dynamically created class's object property
    // delete s4;
    // delete s5;

    // copy object
    Student s6 ;
    s6=s1;
    cout << s6.name << endl;
    //copy object through copy constructure
    Student s7=s1; // OR Student s7(s1);


    return 0;
}