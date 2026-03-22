// Ride.h — Base class for all ride types
// Demonstrates: Encapsulation (private members, public accessors)
//               Polymorphism  (virtual methods overridden by subclasses)

#ifndef RIDE_H
#define RIDE_H

#include <iostream>
#include <string>

class Ride {
private:
    // Encapsulation: data members are private
    int rideID;
    std::string pickupLocation;
    std::string dropoffLocation;
    double distance; // in miles
    double fare;

public:
    // Constructor
    Ride(int id, const std::string& pickup, const std::string& dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff),
          distance(dist), fare(0.0) {}

    // Virtual destructor for proper cleanup through base pointers
    virtual ~Ride() {}

    // ---------- Accessors (encapsulation) ----------
    int getRideID() const { return rideID; }
    std::string getPickupLocation() const { return pickupLocation; }
    std::string getDropoffLocation() const { return dropoffLocation; }
    double getDistance() const { return distance; }
    double getFare() const { return fare; }

    // ---------- Polymorphic methods ----------

    // Pure-virtual: every subclass MUST provide its own fare formula
    virtual double calculateFare() {
        fare = distance * 1.0; // base rate $1.00/mile (fallback)
        return fare;
    }

    // Virtual: subclasses may extend the display
    virtual void rideDetails() const {
        std::cout << "------- Ride Details -------\n";
        std::cout << "  Ride ID       : " << rideID << "\n";
        std::cout << "  Pickup        : " << pickupLocation << "\n";
        std::cout << "  Drop-off      : " << dropoffLocation << "\n";
        std::cout << "  Distance      : " << distance << " miles\n";
        std::cout << "  Fare          : $" << fare << "\n";
    }

protected:
    // Subclasses may update the fare through this setter
    void setFare(double f) { fare = f; }
};

#endif // RIDE_H
