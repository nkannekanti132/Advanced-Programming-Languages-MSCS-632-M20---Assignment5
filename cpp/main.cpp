// main.cpp — Ride Sharing System Demo
// Demonstrates all three OOP principles:
//   1. Encapsulation  – private data accessed via public methods
//   2. Inheritance     – StandardRide & PremiumRide extend Ride
//   3. Polymorphism    – base-class pointers invoke overridden methods

#include <iostream>
#include <vector>
#include "Ride.h"
#include "StandardRide.h"
#include "PremiumRide.h"
#include "Driver.h"
#include "Rider.h"

int main() {
    std::cout << "============================================\n";
    std::cout << "      RIDE SHARING SYSTEM — C++ DEMO        \n";
    std::cout << "============================================\n\n";

    // ---- 1. Create rides of different types ----
    StandardRide ride1(101, "Main St",      "Airport",       12.5);
    StandardRide ride2(102, "Downtown",     "University",     5.0);
    PremiumRide  ride3(201, "Hotel Grand",  "Convention Ctr", 8.0);
    PremiumRide  ride4(202, "Mall",         "Beach Resort",  15.0);

    // ---- 2. Polymorphism: store in a base-class pointer list ----
    std::vector<Ride*> rides = { &ride1, &ride2, &ride3, &ride4 };

    // Calculate fares polymorphically
    std::cout << ">> Calculating fares for all rides...\n\n";
    for (auto* ride : rides) {
        ride->calculateFare();   // calls the correct override
    }

    // Display ride details polymorphically
    std::cout << ">> Displaying ride details...\n\n";
    for (auto* ride : rides) {
        ride->rideDetails();     // calls the correct override
    }

    // ---- 3. Create a Driver and assign rides ----
    Driver driver1(1, "Alice Johnson", 4.8);
    driver1.addRide(&ride1);
    driver1.addRide(&ride3);

    std::cout << ">> Driver information:\n\n";
    driver1.getDriverInfo();

    // ---- 4. Create a Rider and request rides ----
    Rider rider1(1, "Bob Smith");

    std::cout << "\n>> Rider requesting rides:\n\n";
    rider1.requestRide(&ride1);
    rider1.requestRide(&ride4);

    std::cout << "\n>> Rider ride history:\n\n";
    rider1.viewRides();

    // ---- 5. Summary: polymorphic fare comparison ----
    std::cout << ">> Fare Summary (polymorphic call on mixed list):\n";
    std::cout << "   -----------------------------------------\n";
    for (auto* ride : rides) {
        std::cout << "   Ride #" << ride->getRideID()
                  << "  |  " << ride->getDistance() << " mi"
                  << "  |  Fare: $" << ride->getFare() << "\n";
    }
    std::cout << "   -----------------------------------------\n";

    return 0;
}
