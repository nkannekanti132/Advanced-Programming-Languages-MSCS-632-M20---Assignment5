"main.st — Ride Sharing System Demo for GNU Smalltalk"
"Demonstrates all three OOP principles:"
"  1. Encapsulation  — private instance variables accessed via methods"
"  2. Inheritance     — StandardRide & PremiumRide extend Ride"
"  3. Polymorphism    — a single collection of rides invokes overridden methods"

"Load all class definitions"
FileStream fileIn: 'Ride.st'.
FileStream fileIn: 'StandardRide.st'.
FileStream fileIn: 'PremiumRide.st'.
FileStream fileIn: 'Driver.st'.
FileStream fileIn: 'Rider.st'.

Transcript show: '============================================'; cr.
Transcript show: '    RIDE SHARING SYSTEM — SMALLTALK DEMO    '; cr.
Transcript show: '============================================'; cr.
Transcript cr.

"---- 1. Create rides of different types ----"
| ride1 ride2 ride3 ride4 rides driver1 rider1 |

ride1 := StandardRide newWithID: 101 pickup: 'Main St'      dropoff: 'Airport'        distance: 12.5.
ride2 := StandardRide newWithID: 102 pickup: 'Downtown'     dropoff: 'University'      distance: 5.0.
ride3 := PremiumRide  newWithID: 201 pickup: 'Hotel Grand'  dropoff: 'Convention Ctr'  distance: 8.0.
ride4 := PremiumRide  newWithID: 202 pickup: 'Mall'         dropoff: 'Beach Resort'    distance: 15.0.

"---- 2. Polymorphism: store in a single collection ----"
rides := OrderedCollection new.
rides add: ride1; add: ride2; add: ride3; add: ride4.

"Calculate fares polymorphically"
Transcript show: '>> Calculating fares for all rides...'; cr.
Transcript cr.
rides do: [:r | r calculateFare].

"Display ride details polymorphically"
Transcript show: '>> Displaying ride details...'; cr.
Transcript cr.
rides do: [:r | r rideDetails].

"---- 3. Create a Driver and assign rides ----"
driver1 := Driver newWithID: 1 name: 'Alice Johnson' rating: '4.8'.
driver1 addRide: ride1.
driver1 addRide: ride3.

Transcript show: '>> Driver information:'; cr.
Transcript cr.
driver1 getDriverInfo.

"---- 4. Create a Rider and request rides ----"
rider1 := Rider newWithID: 1 name: 'Bob Smith'.

Transcript show: '>> Rider requesting rides:'; cr.
Transcript cr.
rider1 requestRide: ride1.
rider1 requestRide: ride4.

Transcript cr.
Transcript show: '>> Rider ride history:'; cr.
Transcript cr.
rider1 viewRides.

"---- 5. Fare Summary ----"
Transcript show: '>> Fare Summary (polymorphic call on mixed list):'; cr.
Transcript show: '   -----------------------------------------'; cr.
rides do: [:r |
    Transcript show: '   Ride #', r rideID printString,
                     '  |  ', r distance printString, ' mi',
                     '  |  Fare: $', r fare printString; cr.
].
Transcript show: '   -----------------------------------------'; cr.
