#include <iostream>
#include <cstdlib>
#include <time.h>

//Weird class name
class Breast {
public:
    virtual void fix() = 0;
};

class SmallBreast : public Breast {
public:
    void fix() {
        std::cout << "fixes their small breasts\n";
    }

};

class BigBreast : public Breast {
public:
    void fix() {
        std::cout << "fixes their big breasts\n";
    }

};

class BreastFactory {
public:
    BreastFactory (int type) {
        if (type < 1 || type > 2) { breast_ = NULL; }
        else if (type == 1) { breast_ = new SmallBreast(); }
        else if (type == 2) { breast_ = new BigBreast(); }
    }
    ~BreastFactory() {
        if (breast_) {
            breast_ = NULL;
         
        }
    }
    
    Breast* getBreast() {
        return breast_;
    }
    
private:
    Breast* breast_;
    
};



int main() {
    srand(time(NULL));
    BreastFactory* breastFactory = new BreastFactory((rand() % 2 + 1));
    Breast* breast_ = breastFactory->getBreast();
    breast_->fix();

    return 0;
}
