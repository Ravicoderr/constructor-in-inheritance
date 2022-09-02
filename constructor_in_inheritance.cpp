/*
Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/
#include <iostream>
using namespace std;
class base1
{
    int data1;

public:
    base1(int a)
    {
        data1 = a;
        cout<<"constructor of base1 is called "<<endl;
    }
    void printdata1()
    {
        cout<<"the value of a is "<<data1<<endl;
    }

};
class base2
{
    int data2;

public:
    base2(int b)
    {
        data2 = b;
        cout<<"constructor of base2 is called "<<endl;
    }
    void printdata2()
    {
        cout<<"the value of b is "<<data2<<endl;
    }

};
class derived : public base1 , public base2
{
    int derived1 , derived2;
    public:
    derived(int c, int d, int e, int f ) : base1(c) , base2(d)    // this is constuctor of derived class , here we have to define values
    {                                                         // whick are to be given to constructors of base classes
        derived1 = e;
        derived2 = f;
        cout<<"the derived class constructor called "<<endl;
    }
    void printderived()
    {
        cout<<"the value of derived1 and derived2 is "<<derived1<<","<<derived2<<endl;
    }


};
int main(){
    derived ravi(1,2,3,4);
    ravi.printdata1();
    ravi.printdata2();
    ravi.printderived();
    return 0;
}
