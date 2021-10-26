// Observer pattern

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

  virtual void add(IObserver* iObserver) {
    this->observers_.push_back(iObserver);
  }

  virtual void remove(IObserver* iObserver) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), iObserver), observers_.end());
  }

  virtual void notify() {
    std::cout << "Observer report\n";
    for (int i = 0; i < observers_.size(); i++) {
      observers_[i]->update();
    }
  }

private:
  std::vector<IObserver *> observers_;
};

class Observable : public IObservable {
public:
  //Observable();
  //~Observable();

};

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

  Observable observable;
  Observer observer1;
  Observer observer2;
  Observer observer3;

  observable.add(&observer1);
  observable.add(&observer2);
  observable.notify();

  observable.add(&observer3);
  observable.notify();

  observable.remove(&observer2);
  observable.notify();


  return 0;
}
