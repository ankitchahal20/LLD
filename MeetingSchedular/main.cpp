#include <iostream>
#include "scheduler.hpp"

using namespace std;

int main() {
    Scheduler s;
    s.addRoom("MR101");

    s.bookMeeting(1, 2);  // First booking should be successful
    s.bookMeeting(1, 2);  // Second booking should fail due to time overlap

    return 0;
}
