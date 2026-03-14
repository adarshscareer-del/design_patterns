#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Iobserver{
    public:
    virtual void update() = 0;
};

class Iobeserable{
    public:
    virtual void add(Iobserver* o) = 0;
    virtual void remove(Iobserver* o) = 0;
    virtual void notify() = 0;
    virtual void setData(int value) = 0;
    virtual int getData() = 0;
};




class phoneDisplay:public Iobserver{
    int temparature=0;
    Iobeserable* o = nullptr;
    public:
    phoneDisplay(Iobeserable* observerable)
    {
        o = observerable;
    }
    void update()
    {
        temparature = o->getData();
        cout << "phone Display is called and templature is " << temparature <<  endl;
     }

};

class LCDDisplay: public Iobserver{
    int temparature=0;
    Iobeserable* o = nullptr;
    public:
    LCDDisplay(Iobeserable* observerable)
    {
        o = observerable;
    }
    void update() override
    {
        temparature = o->getData();
        cout << "LCD Displayupdate  is called and tempature is " << temparature <<  endl;
     }
};


class weatherStation: public Iobeserable{
    vector<Iobserver*> datas;
    int temparature = 0;
    public:
    weatherStation()
    {
        datas.clear();
    }
    void add(Iobserver* io) override
    {
        datas.push_back(io);
    }
    void remove(Iobserver* io) override
    {
        auto it = find(datas.begin(),datas.end(),io);
        if(it != datas.end())
        datas.erase(it);
        else
        {
            cout << "this element is not present in this" << endl;
        }
    }

    void notify()
    {
        for(auto it: datas)
        {
            it->update();
        }
    }

    void setData(int temp)
    {
        this->temparature = temp;
        notify();
    }

    int getData()
    {
        return temparature;
    }
};


int main()
{
    Iobeserable* ws = new weatherStation();

    Iobserver* phonedisplay1 = new phoneDisplay(ws);
    Iobserver* lcdDisplay1 = new LCDDisplay(ws);
    Iobserver* phonedisplay2 = new phoneDisplay(ws);
    Iobserver* lcdDisplay2 = new LCDDisplay(ws);

    ws->add(phonedisplay1);
    ws->add(lcdDisplay1);
    ws->add(phonedisplay2);
    ws->add(lcdDisplay2);


    ws->setData(10);

    ws->remove(phonedisplay1);


    ws->setData(20);

}


/*
output:
phone Display is called and templature is 10
LCD Displayupdate  is called and tempature is 10
phone Display is called and templature is 10
LCD Displayupdate  is called and tempature is 10
LCD Displayupdate  is called and tempature is 20
phone Display is called and templature is 20
LCD Displayupdate  is called and tempature is 20
*/