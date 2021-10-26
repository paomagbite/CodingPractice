// Observer pattern
// Version 0.5.0
// Written by Dbeela
// Needs a big revision hence 1.0 will be written based of this one soon

#include <iostream>
#include <vector>
#include <algorithm>

// Observer Interface
static int observer_id;
class IObserver {
public:
  IObserver() {
    observer_id++;
  }
  //~IObserver();

  virtual void update() = 0;


};

// Observable interface
class IObservable {
public:
  //IObservable();
  //~IObservable();

  // adds new observer to the observble
  virtual void add(IObserver* iObserver) {
    this->observers_.push_back(iObserver);
  }

  // removes observer
  virtual void remove(IObserver* iObserver) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), iObserver), observers_.end());
  }

  // notifies all the observers of the obejct
  virtual void notify() {
    std::cout << "Observer report\n";
    for (int i = 0; i < observers_.size(); i++) {
      observers_[i]->update();
    }
  }

private:
  std::vector<IObserver *> observers_;
};

// Should implement this instead of having impenetation in the interface
// The observed object
class Observable : public IObservable {
public:
  //Observable();
  //~Observable();

};

// The object that observes and observable
class Observer : public IObserver {
public:
  Observer(): IObserver() {
    this->id = observer_id;
  }
  //~Observer();
  void update() {
    std::cout << "Observer " << id << " reporting in!\n";
  }

private:
  int id;

};




int main () {

  // Initilization of all objects
  Observable observable;
  Observer observer1;
  Observer observer2;
  Observer observer3;

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
