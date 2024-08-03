#pragma once
#include <iostream>
#include <vector>
#include "meeting.hpp"

using namespace std;

class Room {
private:
    string roomName;
    vector<Meeting> bookings;
public:
    Room(string);
    ~Room();
    bool bookRoom(int, int);

    void setRoomName(string);
    string getRoomName();
};
