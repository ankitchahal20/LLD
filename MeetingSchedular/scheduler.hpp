#pragma once
#include <vector>
#include "room.hpp"

using namespace std;

class Scheduler {
private:
    vector<Room> rooms;
public:
    void addRoom(string roomName);
    bool bookMeeting(int startTime, int endTime);
};
