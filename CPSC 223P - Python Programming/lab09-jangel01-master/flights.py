# Name: Jason Angel
# Date: 10/31/21
# Purpose: Module contains Flights class, which practices using datetime module

import json
from datetime import datetime

class Flights:
    def __init__(self, filename,):
        self.filename =  filename
        self.data = []

        try:
            with open(self.filename, 'r') as f:
                self.data = json.load(f)
        except FileNotFoundError:
            pass

    def changeFile(self):
        try:
            with open(self.filename, 'r') as f:
                self.data = json.load(f)
                print("Data will now be populated to " + self.filename)
        except FileNotFoundError:
            self.data = []
            print("File does not exist, however any new data will now be populated to: " + self.filename)

    def add_flight(self, origin, destination, flight, departure, nextday, arrival):
        if departure.isdigit() == False or arrival.isdigit() == False:
            return False

        self.data.append([origin, destination, flight, departure, nextday, arrival])

        with open(self.filename, 'w') as f:
            json.dump(self.data, f)

        return True

    def get_flights(self):
        formattedList = []

        for x in range(len(self.data)):
            origin = self.data[x][0]
            destination = self.data[x][1]
            flight = self.data[x][2]

            # Format departure time
            departureTime = datetime.strptime(self.data[x][3], "%H%M")
            AMorPM = departureTime.strftime("%p").lower()
            departureFormat = departureTime.strftime("%-I:%M") + AMorPM

            # Format arrival time
            arrivalTime = datetime.strptime(self.data[x][5], "%H%M")
            AMorPM = arrivalTime.strftime("%p").lower()
            arrivalFormat = None
            if self.data[x][4].upper() == "Y":
                arrivalFormat = "+" + arrivalTime.strftime("%-I:%M") + AMorPM
            else:
                arrivalFormat = arrivalTime.strftime("%-I:%M") + AMorPM

            # Format duration
            duration = arrivalTime - departureTime
            hours = str(duration.seconds // 3600)
            minutes = duration.seconds % 3600 // 60
            if minutes < 10:
                minutes = str(minutes)
                minutes = minutes.zfill(2)
            else:
                minutes = str(minutes)

            durationFormat = hours + ":" + minutes

            formattedList.append([origin, destination, flight, departureFormat, arrivalFormat, durationFormat])


        return formattedList
