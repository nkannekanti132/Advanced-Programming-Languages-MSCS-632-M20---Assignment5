"Rider.st — Rider (passenger) class"
"Demonstrates: Encapsulation (private requestedRides, public interface)"

Object subclass: Rider [
    | riderID name requestedRides |

    "Class-side constructor"
    Rider class >> newWithID: anID name: aName [
        ^ self new
            initWithID: anID name: aName;
            yourself
    ]

    "Instance-side initializer"
    initWithID: anID name: aName [
        riderID        := anID.
        name           := aName.
        requestedRides := OrderedCollection new.
    ]

    "Encapsulated accessors"
    riderID [ ^ riderID ]
    name    [ ^ name ]

    "Request (book) a ride"
    requestRide: aRide [
        requestedRides add: aRide.
        Transcript show: name, ' requested ride #', aRide rideID printString, '.'; cr.
    ]

    "Display full ride history"
    viewRides [
        Transcript show: '===== Ride History for ', name, ' (ID: ', riderID printString, ') ====='; cr.
        requestedRides isEmpty
            ifTrue:  [ Transcript show: '  No rides requested yet.'; cr ]
            ifFalse: [ requestedRides do: [:ride | ride rideDetails] ].
        Transcript show: '============================================'; cr.
        Transcript cr.
    ]
]
