#include<string>
#include<iostream>
using namespace std;

class Driver{
private:
    string driverName;
public:
    Driver(string);
    void setDriverName(string);
    string getDriverName();
};

Driver::Driver(string driverName){
    this->driverName=driverName;
}

void Driver:: setDriverName(string name){
    this->driverName=name;
}

string Driver:: getDriverName(){
    return driverName;
}