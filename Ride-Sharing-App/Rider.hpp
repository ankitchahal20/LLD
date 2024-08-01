#include<vector>
#include<iostream>
#include "Ride.hpp"
using namespace std;


class Rider
{
private:
    string riderName;
    int id;
    Ride currentRide;
    vector<Ride> completedRides;
public:
    Rider(int, string);
    void createRide(int, int, int, int);
    void startRide();
    void updateRide(int, int, int, int);
    void withdrawRide(int);
    int closeRide(int);
    void setRiderName(string);
    string getRiderName();
    ~Rider();
};

Rider::Rider(int id, string name){
    this->id=id;
    this->riderName=name;
}

void Rider:: startRide(){
    currentRide.setRideStatus(RideStatus::INPROGRESS);
}

void Rider::createRide(int id, int origin, int destination, int totalSeats){
    if(origin>=destination){
        cout<<"Incorrect origin and destination provided, cannot not create ride!!!"<<endl;
        return;
    }
    currentRide.setId(id);
    currentRide.setOrigin(origin);
    currentRide.setDestination(destination);
    currentRide.setTotalSeats(totalSeats);
    currentRide.setRideStatus(RideStatus::BOOKED);
    cout<<"Ride Booked successfully !!!"<<endl;
}

void Rider::updateRide(int id, int origin, int destination, int totalSeats){
    if(currentRide.getRideStatus()==RideStatus::CANCELLED || 
        currentRide.getRideStatus()==RideStatus::COMPLETED){
            cout<<"Ride cannot be updated"<<endl;
            return;
    }

    createRide(id, origin, destination, totalSeats);
}

void Rider::withdrawRide(int id) {
    if(currentRide.getId()!=id) {
        cout<<"\nCannot widthdraw ride, incorrect ride id provided"<<endl;
        return;
    }

    if(currentRide.getRideStatus()==RideStatus::INPROGRESS){
        cout<<"\nCannot widthdraw ride, as the ride is in inprogress"<<endl;
        return;
    }

    currentRide.setRideStatus(RideStatus::CANCELLED);
    cout<<"\ncurrentRide status : "<<currentRide.getRideStatus()<<endl;
    cout<<"Ride Cancelled successfully!!!"<<endl;
}

int Rider::closeRide(int){
    if(currentRide.getRideStatus()==RideStatus::WAITING){ 
        return -1;
    }
    currentRide.setRideStatus(RideStatus::COMPLETED);
    completedRides.push_back(currentRide);
    return currentRide.getFare(completedRides.size()>=10);
}

void Rider:: setRiderName(string name){
    this->riderName=name;
}

string Rider:: getRiderName(){
    return riderName;
}

Rider::~Rider()
{
}
