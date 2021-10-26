// Observer pattern

#include <iostream>
#include <vector>

// Observer Interface
class IObserver {
public:
  IObserver() {
    observer_id++;
  }

  virtual void update();

private:
  static int observer_id = 0;
};

// Observable interface
class IObservable {
public:
  virtual void add(IObserver* iObserver) {
    this->observers_.push_back(iObserver);
  }
  virtual void remove(IObserver* iObserver);
  virtual void notify() {
    for (int i = 0; i < observers_.size(); i++) {
      observers_[i]->update();
    }
  }

private:
  std::vector<IObserver *> observers_;
};

class Observable : IObservable {
public:

};

class Observer : IObserver {
public:
  Observer(): IObserver() {

  }
  void update() {

  }

private:
  int id = 0;

};




int main () {


  return 0;
}
