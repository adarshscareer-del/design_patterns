#include<iostream>
using namespace std;

class Beverage{
    public:
    virtual int cost() = 0;
    virtual string discription() = 0;
};

class Decorator:public Beverage{
    protected:
    Beverage* beverage;
    Decorator(Beverage* b)
    {
        beverage = b;
    }
};

class Latte:public Beverage{
    public:
    int cost() override
    {
        return 10;
    }
    string discription()
    {
        return "Latte added," ;
    }
};

class Expresso:public Beverage{
    public:
    int cost() override
    {
        return 15;
    }
    string discription()
    {
        return "Expresso Done with:" ;
    }
};

class capachino:public Beverage{
    public:
    int cost() override
    {
        return 25;
    }
    string discription() override
    {
        return "Capachino done with:" ;
    }
};


class milkdecorator:public Decorator{
    public:
    milkdecorator(Beverage* b):Decorator(b)
    {
        cout << "Milk added" << endl;
    }
    int cost() override
    {
        return beverage->cost() + 9;
    }

    string discription()
    {
        return beverage->discription() + "milk," ; 
    }

};

class soyadecorator:public Decorator{
    public:
    soyadecorator(Beverage* b):Decorator(b)
    {
        cout << "soya added" << endl;
    }
    int cost() override
    {
        return beverage->cost() + 18;
    }

    string discription()
    {
        return beverage->discription() + "soya," ; 
    }
};

class cochodecorator:public Decorator{
    public:
    cochodecorator(Beverage* b):Decorator(b)
    {
        cout << "chocho added" << endl;
    }
    int cost() override
    {
        return beverage->cost() + 19;
    }

    string discription()
    {
        return beverage->discription() + "cochomilk," ; 
    }
};

class sugardecorator:public Decorator{
    public:
    sugardecorator(Beverage* b):Decorator(b)
    {
        cout << "Milk added" << endl;
    }
    int cost() override
    {
        return beverage->cost() + 99;
    }

    string discription()
    {
        return beverage->discription() + "sugar," ;
    }
};

int main()
{
    Beverage* b = new milkdecorator(new sugardecorator(new capachino()));

    cout << b->cost()  << endl;;
    cout << b->discription() << endl;


    Beverage* b1 = new milkdecorator(new soyadecorator(new capachino()));

    cout << b1->cost()  << endl;;
    cout << b1->discription() << endl;
}

/*
output:
Milk added
Milk added
133
Capachino done with:sugar,milk,
soya added
Milk added
52
Capachino done with:soya,milk,
*/

