/* Command Pattern implementation, this iteration is a bit wrong thought so a new version will be implemented
 *
 * Written by Dbeela
 * Date: 01/11/21
 * Version: 0.0.1
 *
 */

#include <iostream>
#include <vector>

class Light {
public:
    void is_on() {
        std::cout << "Light is: ON\n";
    }
    void is_off() {
        std::cout << "Light is: OFF\n";
    }
};

class ICommand {
public:
    virtual void execute() = 0;

};

class CommandOn : public ICommand {
public: 
    CommandOn(Light* light) {
        this->light = light;
    }

    void execute() {
       this->light->is_on(); 
    }

private:
    Light* light;
};

class CommandOff : public ICommand {
public: 
    CommandOff(Light* light) {
        this->light = light;
    }

    void execute() {
       this->light->is_off(); 
    }

private:
    Light* light;
};

class Invoker {
public:
    Invoker(ICommand* on, ICommand* off) {
        this->on = on;
        this->off = off;
    }
    ICommand* on;
    ICommand* off;

    void press_button() {
        if (lampState) { 
            on->execute(); 
            lampState = 0;
        }
        else { 
            off->execute(); 
            lampState = true;
        }
    }
    
private:
    bool lampState = false;
};


int main () {

    Light light;
    CommandOn on(&light);
    CommandOff off(&light);

    Invoker remote(&on, &off);
    
    for (int i = 0; i < 25; i++) {
        remote.press_button();
    }

    return 0;
}
