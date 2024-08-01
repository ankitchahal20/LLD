#include<iostream>
#include<vector>
using namespace std;
#include "Rider.hpp"
#include "Driver.hpp"



int main() {
	Rider rider(1, "Ankit");
	Driver driver("Amit");
	Rider rider1(2, "Cahala");
	Rider rider2(3, "Ankita");

	vector<Rider> riders;
	riders.push_back(rider);
	riders.push_back(rider1);
	riders.push_back(rider2);

	
	rider.createRide(1, 50, 60, 1);
	rider.startRide();
	rider.withdrawRide(1);

	rider1.createRide(1, 50, 60, 1);
	//rider1.startRide();
	rider1.withdrawRide(1);
	

	return 0;
}