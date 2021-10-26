// Strategy Pattern Implementation
// Written by Dbeela
// Date 26/10/21
// Version 1.0

// Uses the implementation of ducks and different fly behavior
// Requires instatioation of the strategy used but will use the right
// one by pointinf towords the obejct in the code.


#include <iostream>
#include <string>

// Interface and default option
class IFlyingBehavior {
public:
  virtual void fly() { std::cout << "is Flying\n"; }

};

// Implement different flying behavior
class FlyingLong : public IFlyingBehavior {
public:
  void fly() override { std::cout << "is Flying Long\n"; }
};

// Duck class, takiung parameters to build desired duck
// but this does not work atm...

class Duck {
public:

  IFlyingBehavior *iFlyingBehavior_;

  Duck(IFlyingBehavior *iFlyingBehavior = nullptr) : iFlyingBehavior_(iFlyingBehavior) {}

  void set_flying_behavior(IFlyingBehavior *iFlyingBehavior)
    {
        delete this->iFlyingBehavior_;
        this->iFlyingBehavior_ = iFlyingBehavior;
    }

  void fly() {
    this->iFlyingBehavior_->fly();
    // std::cout << iFlyingBehavior.fuckYou << "\n";
  }

};


int main () {

  IFlyingBehavior iFlyingBehavior;
  FlyingLong flyingLong;

  Duck duck1(&iFlyingBehavior);
  Duck duck2(&flyingLong);

  duck1.fly(); // Works as expected
  duck2.fly(); // This returns the parent functions fly(), which is undesired, it is working now
  // flyingLong.fly(); // This returns what I want and means the interface works insofar as presumed...

  return 0;
}
