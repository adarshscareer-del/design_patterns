#include<iostream>
#include<vector>
using namespace std;

class Light{
    public:
    void lightOn(){
        cout << "Light is On" << endl;
    }

    void LighOff()
    {
        cout << "Light is Off" << endl;
    }
};

class TV{
    public:
    void onTV()
    {
        cout << "Tv is ON" << endl;
    }

    void offTV()
    {
        cout << "Tv is OFF" << endl;
    }
};

class mobile{
    public:
    void onMobile(){
        cout << "Mobile is On" << endl;
    }

    void offMobile(){
        cout << "Mobile is Off" << endl;
    }
};

class Icommand{
    public:
    virtual void execute() = 0;
    virtual void unexecute() = 0;
};

class TVcommands:public Icommand{
    TV* tv;
    public:
    TVcommands(TV* tv)
    {
        this->tv = tv;
    }
    void execute() override
    {
        tv->onTV();
    }
    void unexecute() override
    {
        tv->offTV();
    }
};

class MobileCommands: public Icommand
{
    mobile* mb;
    public:
    MobileCommands(mobile* mb)
    {
        this->mb = mb;
    }

    void execute() override
    {
        mb->onMobile();
    }

    void unexecute() override
    {
        mb->offMobile();
    }
};

class LightCommand:public Icommand{

    Light* lt;
    public:
    LightCommand(Light* lt)
    {
        this->lt = lt;
    }

    void execute() override
    {
        lt->lightOn();
    }

    void unexecute() override
    {
        lt->LighOff();
    }
};

class Remote{
    vector<Icommand*> commands;
    public:
    Remote(vector<Icommand*>& commands)
    {
        this->commands = commands;
    }

    void OnTV()
    {
        commands[0]->execute();
    }
    void OnMobile()
    {
        commands[1]->execute();
    }
    void OnLight()
    {
        commands[2]->execute();
    }

    void OffTV()
    {
        commands[0]->unexecute();
    }

    void OffMobile()
    {
        commands[0]->unexecute();
    }

    void OffLight()
    {
        commands[2]->unexecute();
    }
};

int main()
{
    Light* lt = new Light();
    TV* tv = new TV();
    mobile* mb = new mobile();

    LightCommand* ltcommand = new LightCommand(lt);
    TVcommands* TVcommand = new TVcommands(tv);
    MobileCommands* Mobilecmd = new MobileCommands(mb);


    vector<Icommand*> commands = {TVcommand,Mobilecmd,ltcommand};

    Remote* rt = new Remote(commands);

    rt->OffLight();
    rt->OffMobile();
    rt->OffTV();
    rt->OnLight();
    rt->OnTV();
    rt->OnMobile();
}


/*
output:
Light is Off
Tv is OFF
Tv is OFF
Light is On
Tv is ON
Mobile is On
*/