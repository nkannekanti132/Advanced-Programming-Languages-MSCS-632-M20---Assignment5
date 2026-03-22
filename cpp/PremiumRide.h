// PremiumRide.h — Premium ride subclass
// Demonstrates: Inheritance  (extends Ride)
//               Polymorphism (overrides calculateFare & rideDetails)

#ifndef PREMIUMRIDE_H
#define PREMIUMRIDE_H

#include "Ride.h"

class PremiumRide : public Ride {
public:
    PremiumRide(int id, const std::string& pickup, const std::string& dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    // Override: Premium rate is $3.00 per mile + $5.00 base fee
    double calculateFare() override {
        double calculatedFare = getDistance() * 3.00 + 5.00;
        setFare(calculatedFare);
        return calculatedFare;
    }

    // Override: adds ride-type label
    void rideDetails() const override {
        std::cout << "★★★★★ PREMIUM RIDE ★★★★★\n";
        Ride::rideDetails();
        std::cout << "  Rate          : $3.00/mile + $5.00 base\n";
        std::cout << "★★★★★★★★★★★★★★★★★★★★★★★★\n\n";
    }
};

#endif // PREMIUMRIDE_H
