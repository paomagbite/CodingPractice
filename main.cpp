/* Factory pattern file
 * Written by Dbeela
 * Version: 0.0.0
 * Date: 28/10/21
 * Based on the refactoringguru.org Factory pattern
 */

#include <iostream>
#include <string>

bool iequals(const std::string& a, const std::string& b)
{
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

// Product interface for all the other products
class Product {
public:
    virtual ~Product() {}
    virtual std::string operation() = 0;
};

class Phone : public Product {
public:
    std::string operation() override {
        return "{Phone was created}";
    }
};

class Computer : public Product {
public:
    std::string operation() override {
        return "{Computer was created}";
    }
};

// interface to the factory method
class Creator {
public:
    virtual ~Creator() {}
    virtual Product* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        Product* product = this->FactoryMethod();

        std::string result = "Creator: The same creator's code has just worked with " + product->operation();
        delete product;
        return result;
    }
};

class PhoneCreator : public Creator {
public:
    Product* FactoryMethod() const override {
        return new Phone();
    }
};

class ComputerCreator : public Creator {
public:
    Product* FactoryMethod() const override {
        return new Computer();
    }
};

void ClientCode(const Creator& creator) {
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n" 
        << creator.SomeOperation() << std::endl;
}

int main () {
    
    std::cout << "App launched with Phone\n";
    Creator* creator = new PhoneCreator();
    ClientCode(*creator);
    std::cout << std::endl;

    std::cout << "App lanuched on Computer\n";
    Creator* creator2 = new ComputerCreator();
    ClientCode(*creator2);

    delete creator;
    delete creator2;
    return 0;
}
