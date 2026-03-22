"StandardRide.st — Economy ride subclass"
"Demonstrates: Inheritance  (extends Ride)"
"              Polymorphism (overrides #calculateFare and #rideDetails)"

Ride subclass: StandardRide [

    "Constructor inherited from Ride via class method"
    StandardRide class >> newWithID: anID pickup: aPickup dropoff: aDropoff distance: aDist [
        ^ self new
            initWithID: anID pickup: aPickup dropoff: aDropoff distance: aDist;
            yourself
    ]

    "Override: Standard rate is $1.50 per mile"
    calculateFare [
        fare := distance * 1.50.
        ^ fare
    ]

    "Override: display with ride-type label"
    rideDetails [
        Transcript show: '======= STANDARD RIDE ======='; cr.
        super rideDetails.
        Transcript show: '  Rate          : $1.50/mile'; cr.
        Transcript show: '============================='; cr.
        Transcript cr.
    ]
]
