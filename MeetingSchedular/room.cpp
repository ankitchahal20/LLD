#include "room.hpp"

Room::Room(string roomName) {
    this->roomName = roomName;
}

Room::~Room() {
}

bool Room::bookRoom(int startTime, int endTime) {
    for (const auto& meeting : bookings) {
        if (!(endTime <= meeting.startTime || startTime >= meeting.endTime)) {
            return false;
        }
    }
    bookings.emplace_back(startTime, endTime);
    return true;
}

void Room::setRoomName(string roomName) {
    this->roomName = roomName;
}

string Room::getRoomName() {
    return roomName;
}
