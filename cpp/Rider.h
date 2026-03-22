// Rider.h — Rider (passenger) class
// Demonstrates: Encapsulation (private requestedRides, public interface)

#ifndef RIDER_H
#define RIDER_H

#include <iostream>
#include <string>
#include <vector>
#include "Ride.h"

class Rider {
private:
    // Encapsulation: data members are private
    int riderID;
    std::string name;
    std::vector<Ride*> requestedRides; // accessible only through methods

public:
    Rider(int id, const std::string& riderName)
        : riderID(id), name(riderName) {}

    // ---------- Accessors ----------
    int getRiderID() const { return riderID; }
    std::string getName() const { return name; }

    // ---------- Ride management ----------

    // Request (book) a ride
    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
        std::cout << name << " requested ride #" << ride->getRideID() << ".\n";
    }

    // Display full ride history
    void viewRides() const {
        std::cout << "===== Ride History for " << name << " (ID: " << riderID << ") =====\n";
        if (requestedRides.empty()) {
            std::cout << "  No rides requested yet.\n";
        } else {
            for (const auto& ride : requestedRides) {
                ride->rideDetails();
            }
        }
        std::cout << "============================================\n\n";
    }
};

#endif // RIDER_H
