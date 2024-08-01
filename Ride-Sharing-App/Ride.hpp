enum RideStatus {WAITING, BOOKED, INPROGRESS, COMPLETED, CANCELLED};

class Ride
{
private:
    static const int AMT_PER_KM = 20;
    int id;
    int origin, destination;
    int totalSeats;
    RideStatus rideStatus;
public:
    Ride();
    void setId(int);
    void setOrigin(int);
    void setDestination(int);
    void setTotalSeats(int);
    void setRideStatus(RideStatus);

    int getId();
    int getOrigin();
    int getDestination();
    int getTotalSeats();
    RideStatus getRideStatus();

    int getFare(bool);

    ~Ride();
};

Ride::Ride()
{
    id=0;
    destination=0;
    origin=0;
    totalSeats=0;
    rideStatus=WAITING;
}


void Ride:: setId(int id){
    this->id=id;
}

void Ride:: setOrigin(int origin){
    this->origin=origin;
}

void Ride:: setDestination(int destination){
    this->destination=destination;
}

void Ride:: setTotalSeats(int totalSeats){
    this->totalSeats=totalSeats;
}

void Ride:: setRideStatus(RideStatus rideStatus){
    this->rideStatus=rideStatus;
}


int Ride:: getId(){
    return id;
}

int Ride:: getOrigin(){
    return origin;
}

int Ride:: getDestination(){
    return destination;
}

int Ride:: getTotalSeats(){
    return totalSeats;
}

RideStatus Ride:: getRideStatus(){
   return rideStatus;
}

int Ride:: getFare(bool preferredRider){
    int totalFare=0;
    if(preferredRider){
        if(getTotalSeats() >=2 ){
            totalFare=getTotalSeats() * (destination-origin) * 0.75 * AMT_PER_KM;
        } else {
            totalFare=getTotalSeats() * (destination-origin) * 1 * AMT_PER_KM;
        }
    } else {
        if(getTotalSeats() >=2 ){
            totalFare=getTotalSeats() * (destination-origin) * 0.5 * AMT_PER_KM;
        } else {
            totalFare=getTotalSeats() * (destination-origin) * 0.75 * AMT_PER_KM;
        }
    }
    return totalFare;
}

Ride::~Ride()
{
}


