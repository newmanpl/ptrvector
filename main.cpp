// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Base {
public:
        virtual void foo() {
          cout<<"Base::foo"<<endl;
        }
};

class avcontrol : public Base {
public:
         static Base* create(int, float) {
                cout << "call avcontrol"<<endl;
                return new avcontrol();
        }
        void foo() {
                cout<<"avcontrol::foo"<<endl;
        }
};

class configuration : public Base {
public:
         static Base* create(int, float) {
                cout << "call configuration"<<endl;
                return new configuration();
        }
        void foo() {
                cout<<"configuration::foo"<<endl;
        }
};

typedef Base*(*FuncPtr)(int c, float t);
int main() {
        std::vector<FuncPtr> v;

        v.push_back(&avcontrol::create);
        v.push_back(&configuration::create);
        for(int i=0;i<(int)v.size();++i) {
                Base* b = v[i](4, 3.0);
                b->foo();
        }

        return 0;
}

