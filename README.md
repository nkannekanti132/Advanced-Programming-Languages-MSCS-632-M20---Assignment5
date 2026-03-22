# Ride Sharing System — OOP Assignment

A class-based **Ride Sharing System** implemented in **C++** and **GNU Smalltalk**, demonstrating three core OOP principles: **encapsulation**, **inheritance**, and **polymorphism**.

---

## Project Structure

```
├── cpp/
│   ├── Ride.h            # Base ride class
│   ├── StandardRide.h    # Economy ride subclass
│   ├── PremiumRide.h     # Premium ride subclass
│   ├── Driver.h          # Driver class
│   ├── Rider.h           # Rider (passenger) class
│   └── main.cpp          # Demo program
│
├── smalltalk/
│   ├── Ride.st           # Base ride class
│   ├── StandardRide.st   # Economy ride subclass
│   ├── PremiumRide.st    # Premium ride subclass
│   ├── Driver.st         # Driver class
│   ├── Rider.st          # Rider (passenger) class
│   └── main.st           # Demo script
│
└── README.md
```

---

## How to Build & Run

### C++

Requires a C++17 compiler (g++ or clang++).

```bash
cd cpp
g++ -std=c++17 -o rideshare main.cpp
./rideshare
```

### Smalltalk (GNU Smalltalk)

Requires GNU Smalltalk (`gst`).

```bash
cd smalltalk
gst main.st
```

---

## OOP Principles Demonstrated

### 1. Encapsulation

| Language   | How |
|------------|-----|
| **C++**    | All data members (`rideID`, `distance`, `assignedRides`, etc.) are declared `private`. Access is provided through public getter/setter methods and controlled interfaces like `addRide()` and `requestRide()`. |
| **Smalltalk** | Instance variables are inherently private. Public accessor methods (`rideID`, `name`, `addRide:`, etc.) provide controlled access. Collections like `assignedRides` and `requestedRides` are never exposed directly. |

### 2. Inheritance

| Language   | How |
|------------|-----|
| **C++**    | `StandardRide` and `PremiumRide` inherit from the `Ride` base class using `public` inheritance, reusing attributes and methods while providing specialized behavior. |
| **Smalltalk** | `StandardRide` and `PremiumRide` are defined as subclasses of `Ride`, automatically inheriting all instance variables and methods. |

### 3. Polymorphism

| Language   | How |
|------------|-----|
| **C++**    | `calculateFare()` and `rideDetails()` are declared `virtual` in the base class and overridden in each subclass. A `vector<Ride*>` stores mixed ride types, and calling these methods on base-class pointers dispatches to the correct overridden version at runtime. |
| **Smalltalk** | Smalltalk uses dynamic dispatch by default — all message sends are polymorphic. An `OrderedCollection` holds `StandardRide` and `PremiumRide` objects, and sending `calculateFare` or `rideDetails` dispatches to the appropriate overridden method automatically. |

---

## Sample Output

Both implementations produce equivalent output showing:
- Fare calculations for Standard ($1.50/mile) and Premium ($3.00/mile + $5.00 base) rides
- Driver information with completed ride list
- Rider ride request and history
- A polymorphic fare summary over a mixed collection of ride types
