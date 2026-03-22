"PremiumRide.st — Premium ride subclass"
"Demonstrates: Inheritance  (extends Ride)"
"              Polymorphism (overrides #calculateFare and #rideDetails)"

Ride subclass: PremiumRide [

    "Constructor inherited from Ride via class method"
    PremiumRide class >> newWithID: anID pickup: aPickup dropoff: aDropoff distance: aDist [
        ^ self new
            initWithID: anID pickup: aPickup dropoff: aDropoff distance: aDist;
            yourself
    ]

    "Override: Premium rate is $3.00 per mile + $5.00 base fee"
    calculateFare [
        fare := (distance * 3.00) + 5.00.
        ^ fare
    ]

    "Override: display with premium ride-type label"
    rideDetails [
        Transcript show: '***** PREMIUM RIDE *****'; cr.
        super rideDetails.
        Transcript show: '  Rate          : $3.00/mile + $5.00 base'; cr.
        Transcript show: '************************'; cr.
        Transcript cr.
    ]
]
