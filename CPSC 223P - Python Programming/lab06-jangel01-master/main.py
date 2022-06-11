# Name: Jason Angel
# Date: 10/15/21
# Purpose: Practice with string format using nested dict

from weather import *
from datetime import datetime
import calendar

dict = {}

choice = 0

while choice != 9:
    print("*** TUFFY TITAN WEATHER LOGGER MAIN MENU")
    print("1. Set data filename")
    print("2. Add weather data")
    print("3. Print daily report")
    print("4. Print historical report")
    print("9. Exit the program")

    choice = int(input("Enter menu choice: "))

    if choice == 1:
        filename = input("Enter data filename: ")
        dict = read_data(filename = filename)
    elif choice == 2:
        date = input("Enter date (YYMMDD): ")
        time = input("Enter time (hhmmss): ")
        temperature = int(input("Enter temperature: "))
        humidity = int(input("Enter humidity: "))
        rainfall = float(input("Enter rainfall: "))

        weather_key = date + time

        dict[weather_key] = {'t' : temperature, 'h' : humidity, 'r' : rainfall}

        write_data(data = dict, filename = 'myfile.dat')
    elif choice == 3:
        date = input("Enter date (YYMMDD): ")

        print("================================DAILY REPORT================================")
        print("Date                   Time               Temperature     Humidity        Rainfall")
        for key, value in dict.items():
          if date in key:
            datetime_obj = datetime.strptime(key, '%Y' '%m' '%d' '%H' '%M' '%S')
            print(f'{calendar.month_name[datetime_obj.month]} {datetime_obj.day}, {datetime_obj.year:<15}'
            f'{datetime_obj.hour}:{datetime_obj.minute}:{datetime_obj.second:<15}'
            f'{value["t"]:<15} {value["h"]:<15} {value["r"]}')

    elif choice == 4:
      print("================================HISTORICAL REPORT================================")
      print("Date                      Min Temp     Max Temp         Min Hum         Max Hum    Total Rainfall")

      date = None
      datetime_obj = None
      sameDate = False

      for key, value in dict.items():
        if sameDate == True and date not in key:
          sameDate = False

        if sameDate == False:
          date = key[:8]
          datetime_obj = datetime.strptime(key, '%Y' '%m' '%d' '%H' '%M' '%S')

        if date in key and sameDate == False:
          maxTemp = max_temperature(data = dict, date = date)
          minTemp = min_temperature(data = dict, date = date)
          maxHum = max_humidity(data = dict, date = date)
          minHum = min_humidity(data = dict, date = date)
          totalRain = tot_rain(data = dict, date = date)

          print(f'{calendar.month_name[datetime_obj.month]} {datetime_obj.day}, {datetime_obj.year:<15}'
          f'{minTemp:<15} {maxTemp:<15} {minHum:<15} {maxHum:<15} {totalRain}')

          sameDate = True
