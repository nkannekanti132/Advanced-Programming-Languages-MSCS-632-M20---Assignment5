// Driver.h — Driver class
// Demonstrates: Encapsulation (private assignedRides, public interface)

#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include <vector>
#include "Ride.h"

class Driver {
private:
    // Encapsulation: all data is private
    int driverID;
    std::string name;
    double rating;
    std::vector<Ride*> assignedRides; // accessible only through public methods

public:
    Driver(int id, const std::string& driverName, double driverRating)
        : driverID(id), name(driverName), rating(driverRating) {}

    // ---------- Accessors ----------
    int getDriverID() const { return driverID; }
    std::string getName() const { return name; }
    double getRating() const { return rating; }

    // ---------- Ride management (controlled access) ----------

    // Add a completed ride to the driver's record
    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    // Return number of completed rides
    int getTotalRides() const {
        return static_cast<int>(assignedRides.size());
    }

    // Display driver information and all assigned rides
    void getDriverInfo() const {
        std::cout << "========== Driver Info ==========\n";
        std::cout << "  Driver ID : " << driverID << "\n";
        std::cout << "  Name      : " << name << "\n";
        std::cout << "  Rating    : " << rating << " / 5.0\n";
        std::cout << "  Completed : " << assignedRides.size() << " ride(s)\n";
        std::cout << "=================================\n\n";

        for (const auto& ride : assignedRides) {
            ride->rideDetails();
        }
    }
};

#endif // DRIVER_H
