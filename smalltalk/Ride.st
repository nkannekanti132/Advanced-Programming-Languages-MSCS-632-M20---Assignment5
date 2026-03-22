"Ride.st — Base class for all ride types"
"Demonstrates: Encapsulation (instance variables with accessor methods)"
"              Polymorphism  (subclasses override #calculateFare)"

Object subclass: Ride [
    | rideID pickupLocation dropoffLocation distance fare |

    "Class-side constructor"
    Ride class >> newWithID: anID pickup: aPickup dropoff: aDropoff distance: aDist [
        ^ self new
            initWithID: anID pickup: aPickup dropoff: aDropoff distance: aDist;
            yourself
    ]

    "Instance-side initializer"
    initWithID: anID pickup: aPickup dropoff: aDropoff distance: aDist [
        rideID          := anID.
        pickupLocation  := aPickup.
        dropoffLocation := aDropoff.
        distance        := aDist.
        fare            := 0.
    ]

    "Encapsulated accessor methods"
    rideID          [ ^ rideID ]
    pickupLocation  [ ^ pickupLocation ]
    dropoffLocation [ ^ dropoffLocation ]
    distance        [ ^ distance ]
    fare            [ ^ fare ]

    "Calculate fare — base implementation ($1.00/mile)"
    calculateFare [
        fare := distance * 1.0.
        ^ fare
    ]

    "Display ride details"
    rideDetails [
        Transcript show: '------- Ride Details -------'; cr.
        Transcript show: '  Ride ID       : ', rideID printString; cr.
        Transcript show: '  Pickup        : ', pickupLocation; cr.
        Transcript show: '  Drop-off      : ', dropoffLocation; cr.
        Transcript show: '  Distance      : ', distance printString, ' miles'; cr.
        Transcript show: '  Fare          : $', fare printString; cr.
    ]
]
