#include <bits/stdc++.h>
using namespace std;

/* Interface for execute and undo commands */
class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

/* Receiver
   It will receive command and act
*/
class Light {
public:
    void TurnOn() {
        cout<<"Light is On"<<endl;
    }
    void TurnOff() {
        cout<<"Light is Off"<<endl;
    }
};

/* Concrete Implemenatations:
    of on and off cmd
*/

class TurnOnCmd : public ICommand {
private:
    Light *lgt;
    
public: 
    TurnOnCmd (Light *l) : lgt(l) {}
    
    void execute() override {
        lgt->TurnOn();
    }
    
    void undo() override {
        lgt->TurnOff();
    }
};

class TurnOffCmd : public ICommand {
private:
    Light *lgt;
    
public: 
    TurnOffCmd (Light *l) : lgt(l) {}
    
    void execute() override {
        lgt->TurnOff();
    }
    
    void undo() override {
        lgt->TurnOn();
    }
};

// External remote through which commands are called
class RemoteControl {
private:
    ICommand *cmd;
    stack<ICommand*> history;
    
public:
    void SetRemoteControl(ICommand *c) {
        cmd=c;
    }
        
    
    void PressDo() {
        cmd->execute();
        history.push(cmd);
    }
    
    void PressUndo() {
        if(history.size()!=0){
            ICommand* cd = history.top();
            history.pop();
            
            cd->undo();
        }
        else{
            cout<<"No command in undo stack"<<endl;
        }
    }
};

int main() {
    
    Light l;
    
    TurnOnCmd ton(&l);
    TurnOffCmd tof(&l);
    
    RemoteControl R;
    
    R.SetRemoteControl(&ton);
    R.PressDo();
    
    R.SetRemoteControl(&tof);
    R.PressDo();
    
    R.PressUndo();
    R.PressUndo();
    R.PressUndo();
    
    cout<<"Done for the day!"<<endl;

}
