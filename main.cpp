// Observer pattern
// Version 1.0.0
// Written by Dbeela
// Revised version of the observer pattern, added the missing functionality

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Observer Interface
//static int observer_id;
class IObserver {
public:
  virtual void update() = 0;
};

// Observable interface
class IObservable {
public:
  virtual void add(IObserver* iObserver) = 0;

  virtual void remove(IObserver* iObserver) = 0;

  virtual void notify() = 0;
};

// The observed object, child of the IObserver
class Observable : public IObservable {
public:
  // implements add method
  void add(IObserver* iObserver) override {
    this->observers_.push_back(iObserver);
  }

  // implemnents remove method
  void remove(IObserver* iObserver) override {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), iObserver), observers_.end());
  }

  // implements notify function
  void notify() override {
    std::cout << "Observer report\n";
    for (int i = 0; i < observers_.size(); i++) {
      observers_[i]->update();
    }
  }

  // provides a random number which the observer is waiting for.
  int getRanNum() {
    return rand() % 100;
  }

private:
  std::vector<IObserver *> observers_;
};

// The object that observes and observable
class Observer : public IObserver {
public:
  Observer(Observable* observable) {
    this->id = observer_id++;
    this->observable = observable;
    //observable->add(this); // This piece of code is really cool but there are instances where this is very undesirable
  }

  // implements the update method to get the random number and shout it out.
  void update() override {
    num = this->observable->getRanNum();
    std::cout << "Observer " << id << " reporting in and got number: " << num << "\n";
  }

private:
  int id;
  int num;

  static int observer_id;

  Observable* observable;
};

// I am not sure this must be initilised here...
int Observer::observer_id = 0;

int main () {

  // Initilization of all objects
  Observable observable;
  Observer observer1(&observable);
  Observer observer2(&observable);
  Observer observer3(&observable);

  // Test Code, tests add and notify
  observable.add(&observer1);
  observable.add(&observer2);
  observable.notify();

  observable.add(&observer3);
  observable.notify();

  // test code testing remove and notify again
  observable.remove(&observer2);
  observable.notify();


  return 0;
}
