#include<iostream>
using namespace std;

class buttons{
    public:
    virtual void rendor() = 0;
};

class checkbox{
    public:
    virtual void rendor() = 0;
};

class MSbutton:public buttons{
    public:
    void rendor()
    {
        cout << "MSbutton clicked" << endl;
    }  
};

class Macbutton:public buttons{
    public:
    void rendor()
    {
        cout << "Macbutton clicked" << endl;
    }  
};
class MScheckbox:public checkbox{
    public:
    void rendor()
    {
        cout << "MScheckBox clicked" << endl;
    }
};

class Maccheckbox:public checkbox{
    public:
    void rendor()
    {
        cout << "MaccheckBox clicked" << endl;
    }
};

class IAbstracfactor
{
    public:
    virtual buttons* getButton() = 0;
    virtual checkbox* getcheckbox() = 0;
};

class MSfactory: public IAbstracfactor{
    public:
    buttons* getButton()
    {
        return new MSbutton();
    }
    checkbox* getcheckbox()
    {
        return new MScheckbox();
    }
};

class Macfactory: public IAbstracfactor{
    public:
    buttons* getButton()
    {
        return new Macbutton();
    }

    checkbox* getcheckbox()
    {
        return new Maccheckbox();
    }
};


int main()
{
    MSfactory* msf = new MSfactory();
    Macfactory* macf = new Macfactory();

    buttons* msb = msf->getButton();
    buttons* macb = macf->getButton();

    checkbox* msc = macf->getcheckbox();
    checkbox* macc = macf->getcheckbox();
    msb->rendor();
    macb->rendor();

    msc->rendor();
    macb->rendor();

}


/*
output:
MSbutton clicked
Macbutton clicked
MaccheckBox clicked
Macbutton clicked
*/