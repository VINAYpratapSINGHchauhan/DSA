#include <iostream>
#include <string>
using namespace std;
class bird
{
public:
    int age, weight;
    string color;
    void eat()
    {
        cout << "bird is eating " << endl;
    }
    void fly()
    {
        cout << "bird is flying " << endl;
    }
};
class sparrow : public bird
{
    public:
    sparrow(int age , int weight, string color){
        this->age=age;
        this->color=color;
        this->weight=weight;
    }
    void grassing(){
        cout<<"bird is grassing "<<endl;
    }
};
class pegion : public bird
{
    public:
    void guttering(){
        cout<<"bird is guttering "<<endl;
    }
};
int main()
{
    sparrow s(10,32,"green");
    cout<<s.color<<endl;
    pegion p;
    return 0;
}