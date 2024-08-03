#include "scheduler.hpp"

void Scheduler::addRoom(string roomName) {
    rooms.emplace_back(roomName);
}

bool Scheduler::bookMeeting(int startTime, int endTime) {
    for (auto& room : rooms) {
        if (room.bookRoom(startTime, endTime)) {
            cout << "Room " << room.getRoomName() << " booked successfully!" << endl;
            return true;
        }
    }
    cout << "No room available for the given time slot." << endl;
    return false;
}
