// Strategy Pattern Implementation
// Written by Dbeela
// Date 26/10/21
// Version 1.0

// Uses the implementation of ducks and different fly behavior
// Requires instatioation of the strategy used but will use the right
// one by pointinf towords the obejct in the code.


#include <iostream>
#include <string>

// Interface and default flying behavior
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
class Duck {
public:

  IFlyingBehavior *iFlyingBehavior_; // Will use ptr to point towards desired flying behavior

  // Constructor takes a pointer towards an object, to use the desired flying behavior
  Duck(IFlyingBehavior *iFlyingBehavior = nullptr) : iFlyingBehavior_(iFlyingBehavior) {}

  // Function allows for the chainging of flying behavior
  void set_flying_behavior(IFlyingBehavior *iFlyingBehavior)
    {
        // delete this->iFlyingBehavior_; // I think this is unecessary.
        this->iFlyingBehavior_ = iFlyingBehavior;
    }

  void fly() {
    this->iFlyingBehavior_->fly();
  }

};


int main () {

  IFlyingBehavior iFlyingBehavior;
  FlyingLong flyingLong;

  // Object must be passed as a reference for Duck to access the flying behavior
  Duck duck1(&iFlyingBehavior);
  Duck duck2(&flyingLong);

  duck1.fly();
  duck2.fly();

  duck1.set_flying_behavior(&flyingLong);
  duck1.fly();

  return 0;
}
