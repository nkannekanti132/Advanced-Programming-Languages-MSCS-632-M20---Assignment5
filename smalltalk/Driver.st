"Driver.st — Driver class"
"Demonstrates: Encapsulation (private assignedRides, public interface)"

Object subclass: Driver [
    | driverID name rating assignedRides |

    "Class-side constructor"
    Driver class >> newWithID: anID name: aName rating: aRating [
        ^ self new
            initWithID: anID name: aName rating: aRating;
            yourself
    ]

    "Instance-side initializer"
    initWithID: anID name: aName rating: aRating [
        driverID      := anID.
        name          := aName.
        rating        := aRating.
        assignedRides := OrderedCollection new.
    ]

    "Encapsulated accessors"
    driverID [ ^ driverID ]
    name     [ ^ name ]
    rating   [ ^ rating ]

    "Add a ride to the driver's completed list (controlled access)"
    addRide: aRide [
        assignedRides add: aRide.
    ]

    "Return the number of completed rides"
    totalRides [
        ^ assignedRides size
    ]

    "Display driver information and all assigned rides"
    getDriverInfo [
        Transcript show: '========== Driver Info =========='; cr.
        Transcript show: '  Driver ID : ', driverID printString; cr.
        Transcript show: '  Name      : ', name; cr.
        Transcript show: '  Rating    : ', rating, ' / 5.0'; cr.
        Transcript show: '  Completed : ', assignedRides size printString, ' ride(s)'; cr.
        Transcript show: '================================='; cr.
        Transcript cr.

        assignedRides do: [:ride | ride rideDetails].
    ]
]
