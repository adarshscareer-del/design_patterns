#include<iostream>
using namespace std;

class singleton{
    private:
    static singleton* instances;
    singleton(){};

    public:
    static singleton* getInstance()
    {
        if(instances == nullptr)
        {
        instances = new singleton();
        cout << "one and only instance is created" << endl;
        }
        else{
        cout << "Already created instance" << endl;
     
        }
        return instances;
    }
};

singleton* singleton::instances = nullptr;

int main()
{
    singleton* instance = singleton::getInstance();
}

/*
output:
one and only instance is created
*/