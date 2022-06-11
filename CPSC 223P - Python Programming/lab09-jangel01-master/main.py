# Name: Jason Angel
# Date: 10/31/21
# Purpose: Execute methods contained in Flights.py and create a flight schedule list

from flights import *

flights = Flights("default.dat")

choice = 0

while choice != 9:
    print(""" ***TUFFY TITAN FLIGHT SCHEDULE MAIN MENU
    1. Add Flight
    2. Print Flight Schedule
    3. Set flight schedule filename
    9. Exit the program """)

    choice = int(input("Enter menu choice: "))

    if choice == 1:
        origin = input("Enter origin: ")
        destination = input("Enter destination: ")
        flightNumber = input("Enter flight number: ")
        departureTime = input("Enter departure time: ")
        arrivalTime = input("Enter arrival time: ")
        isNextDay = input("Is arrival next day (Y/N): ")

        flights.add_flight(origin, destination, flightNumber, departureTime, isNextDay, arrivalTime)
    elif choice == 2:
        formattedList = flights.get_flights()
        headerLine = "=" * 19
        print(headerLine + " FLIGHT SCHEDULE " + headerLine)
        print("Origin Destination Number Departure   Arrival Duration")
        print("====== =========== ====== =========   ======= ========")
        for x in range(len(formattedList)):
            print(f'{formattedList[x][0]:6} {formattedList[x][1]:9} {formattedList[x][2]:>8}'
            f'{formattedList[x][3]:>10} {formattedList[x][4]:>9} {formattedList[x][5]:>8}')
    elif choice == 3:
        flights.filename = input("Set filename: ")
        flights.changeFile()
