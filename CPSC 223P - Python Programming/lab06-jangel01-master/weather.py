# Name: Jason Angel
# Date: 10/15/21
# Purpose: Module contains functions relevant to the assignment

import json

def read_data(*, filename):
  """Return dict if requested file is found, otherwise return an empty dict"""

  try:
     with open(filename, 'r') as f:
       data = json.load(f)
       return data
  except FileNotFoundError:
       emptyDict = {}
       return emptyDict

def write_data(*, data, filename):
  """Write data to file"""
  with open(filename, 'w') as f:
      json.dump(data, f)

def max_temperature(*, data, date):
  """Return max temp of the date specified"""
  max_temp = 0

  for weatherDict, readingDict in data.items():
      if str(date) in weatherDict:
          temp = readingDict.get('t')
          if max_temp < temp:
              max_temp = temp

  return max_temp

def min_temperature(*, data, date):
  """Return min temp of the date specified"""
  min_temp = 1000

  for weatherDict, readingDict in data.items():
      if str(date) in weatherDict:
          temp = readingDict.get('t')
          if min_temp > temp:
              min_temp = temp

  return min_temp

def max_humidity(*, data, date):
  """Return max hum of the date specified"""
  max_humidity = 0

  for weatherDict, readingDict in data.items():
      if str(date) in weatherDict:
          humidity = readingDict.get('h')
          if max_humidity < humidity:
              max_humidity = humidity

  return max_humidity

def min_humidity(*, data, date):
  """Return min hum of the date specified"""
  min_humidity = 1000

  for weatherDict, readingDict in data.items():
      if str(date) in weatherDict:
          humidity = readingDict.get('h')
          if min_humidity > humidity:
              min_humidity = humidity

  return min_humidity

def tot_rain(*, data, date):
  """Return total rain of the date specified"""
  total_rain = 0

  for weatherDict, readingDict in data.items():
      if str(date) in weatherDict:
          rain = readingDict.get('r')
          total_rain = total_rain + rain

  return total_rain
