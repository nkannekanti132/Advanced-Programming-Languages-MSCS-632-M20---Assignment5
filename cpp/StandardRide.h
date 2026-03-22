// StandardRide.h — Economy ride subclass
// Demonstrates: Inheritance  (extends Ride)
//               Polymorphism (overrides calculateFare & rideDetails)

#ifndef STANDARDRIDE_H
#define STANDARDRIDE_H

#include "Ride.h"

class StandardRide : public Ride {
public:
    // Inherits all base-class members; passes data to Ride constructor
    StandardRide(int id, const std::string& pickup, const std::string& dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    // Override: Standard rate is $1.50 per mile
    double calculateFare() override {
        double calculatedFare = getDistance() * 1.50;
        setFare(calculatedFare);
        return calculatedFare;
    }

    // Override: adds ride-type label
    void rideDetails() const override {
        std::cout << "======= STANDARD RIDE =======\n";
        Ride::rideDetails();     // reuse base display
        std::cout << "  Rate          : $1.50/mile\n";
        std::cout << "=============================\n\n";
    }
};

#endif // STANDARDRIDE_H
