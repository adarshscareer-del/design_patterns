//----------------------------------writing bad code------------------------------------------#
#include<iostream>
using namespace std;
class duck{
    public:
    void fly()
    {
        cout << "Normal fly" << endl;
    }
    void quack()
    {
        cout << "Normal quack" << endl;
    }
};

class mountain_duck:public duck{
    public:
    void fly()
    {
        cout << "mountain_duck_fly" << endl;
    }
    void quack()
    {
        cout << "mountain_duck_quack" << endl;
    }
};

class sea_duck: public duck{
    public:
    void fly()
    {
        cout << "sea_duck_fly" << endl;
    }
    void quack()
    {
        cout << "sea_duck_quack" << endl;
    }
};

class mountain_sea_duck:public duck
{
    public:
    void fly()
    {
        cout << "mountain_duck_fly" << endl;
    }
    void quack()
    {
        cout << "sea_duck_quack" << endl;
    }

    // this class have same fly function as mountain class fly function as quack class
    // we are duplication same code because in heritance we can't inherite from paralle naoubers.
    //so in inheritance it is a draw back. 
    //this problem can be solved by strategy pattern
};

int main()
{
    mountain_duck md;
    mountain_sea_duck msd;
    sea_duck sd;

    md.fly();
    md.quack();

    msd.fly();
    msd.quack();

    sd.fly();
    sd.quack();

    return 0;
}
