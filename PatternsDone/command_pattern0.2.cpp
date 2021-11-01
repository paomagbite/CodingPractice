/* Command Pattern implementation, this iteration is more corrrect and I think it is indicative of a comman pattern now
 *
 * Written by Dbeela
 * Date: 01/11/21
 * Version: 0.0.2
 *
 */

#include <iostream>
#include <vector>

class Light {
public:
    void changeLampState() {
        if (lampState) {
            is_off();
            lampState = false;
        }
        else {
            is_on();
            lampState = true;
        }
    }

private:
    bool lampState = 0;
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

class LampCommand : public ICommand {
public: 
    LampCommand(Light* light) {
        this->light = light;
    }

    void execute() {
       this->light->changeLampState(); 
    }

private:
    Light* light;
};


class Invoker {
public:
    Invoker(ICommand* lampCommand) {
        this->lampStateChange = lampCommand;
    }

    void press_button() {
        lampStateChange->execute();
    }


private:
    ICommand* lampStateChange;
};


int main () {

    Light light;
    LampCommand lamp(&light);

    Invoker remote(&lamp);
    
    for (int i = 0; i < 25; i++) {
        remote.press_button();
    }

    return 0;
}
