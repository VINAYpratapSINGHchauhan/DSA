#include <iostream>
#include <string>
using namespace std;
// class bird
// {
// public:
//     int age, weight;
//     string color;
//     void eat()
//     {
//         cout << "bird is eating " << endl;
//     }
//     void fly()
//     {
//         cout << "bird is flying " << endl;
//     }
// };
// class sparrow : public bird
// {
//     public:
//     sparrow(int age , int weight, string color){
//         this->age=age;
//         this->color=color;
//         this->weight=weight;
//     }
//     void grassing(){
//         cout<<"bird sparrow is grassing "<<endl;
//     }
// };
// class pegion : public bird //public(mode of inheritance) -> parent/base class ka public  data kis mode mei inherit krna hai bo btata hai
// {
//     public:
//     void guttering(){
//         cout<<"bird pegion is guttering "<<endl;
//     }
// };

// multiple inheritance & diamond problem
class person
{
public:
    void walk()
    {
        cout << "walking..." << endl;
    }
};
class Teacher : virtual public person
{
public:
    void teach()
    {
        cout << "teaching..." << endl;
    }
};
class Researcher : virtual public person
{
public:
    void research()
    {
        cout << "reasearching..." << endl;
    }
};

// multiple inheritance
class professor : public Teacher, public Researcher
{
public:
    void bore()
    {
        cout << "boring..." << endl;
    }
};

// for operator overloading
class op
{
    int x, y;

public:
    op(int x, int y) : x(x), y(y) {};
    void display()
    {
        cout << "x:" << x << " y:" << y << endl;
    }
    // ex: + operator overloading
    op operator+(const op&src){
        this->x +=src.x;
        this->y +=src.y;
    } 
    //ex: ++ operator overloading
    op operator++(){
        this->x++;
        this->y++;
    }
};

//runtime polymorphism 
class animal{
    public :
    void sound(){
        cout<<"animal making sound"<<endl;
    }
};
class dog : public animal{
    public :
    void sound(){ //sound function is overidden here
        cout<<"dog is making sound"<<endl;
    }
};
void sound(animal *animal){
    animal->sound();
}
int main()
{
    // sparrow s(10, 32, "green");
    // cout << s.color << endl;
    // s.eat();
    // s.grassing();
    // pegion p;
    // p.eat();
    // p.guttering();

    // // multiple inheritance
    // professor p;
    // p.bore();

    // p.walk(); //will give an error showing that  walk is ambigous that compiler ko smj ni aa rha konsa walk lena hai, as p(object of professor class) is derived from two classes and walk is present in both classes therefore smj ni aarha ki teacher wala walk jo person se aaya ya researcher wala walk jo person se aaya konsa use krna hai. this problem is called diamond problem.

    // soloution to upper problem is : 1. scope resolution 2. using virtual

    // // scope wala solution - btana ki konsa use krna hai
    // p.Teacher::walk();    // here teacher walk is used
    // p.Researcher::walk(); // here researcher walk is used

    // // virtual use krna -btana ki dono ka walk ek hi cheez hai
    // //  diamond probelm mei person class ko inheit krte time virtua use kro
    // p.walk();

    // polymorphism

    // // type 1- compile type polymorphism
    // //  1. function overloading - ex: parameterized constructor
    // //  2. operator overloading - ex: operator overloading used  in op class
    // op op1(5,7);
    // op1.display();
    // op op2(9,3);
    // op1+op2;
    // op1.display();
    // ++op2;
    // op2.display();

    // type 2- runtime polymorphism
    // 1. function overriding 
    dog d1;
    d1.sound(); //sound is overridden here
    dog *d2=new dog();
    d2->sound();
    animal *d3=new dog();  //this is static binding or early binding
    sound(d3); //hme krna dog ka sound call hai but hua animal hai kyuki dog runtime mei bnne se phle animal ka pointer compile tim emei bn chuka hai therefore animal ka sound call hua this is static binding problem that it ye function call statically or compile time mei animal se assoisiate ho gyi.
    return 0;
}