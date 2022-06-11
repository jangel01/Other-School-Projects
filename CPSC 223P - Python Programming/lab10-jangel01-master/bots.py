# Name: Jason Angel
# Date: November 28 2021
# Purpose: Practice threading

import threading
import json
import time

def bot_clerk(items_list):
    cart_list = []
    lock = threading.Lock()
    # rf -> robot fetcher
    rf1 = []
    rf2 = []
    rf3 = []

    for i, v in enumerate(items_list):
        n = i % 3
        if n == 0:
            rf1.append(v)
        elif n == 1:
            rf2.append(v)
        else:
            rf3.append(v)

    # bf -> bot fetcher
    bf1 = threading.Thread(target = bot_fetcher, args = (rf1, cart_list, lock))
    bf2 = threading.Thread(target = bot_fetcher, args = (rf2, cart_list, lock))
    bf3 = threading.Thread(target = bot_fetcher, args = (rf3, cart_list, lock))

    bf1.start()
    bf2.start()
    bf3.start()

    bf1.join()
    bf2.join()
    bf3.join()

    return cart_list

def bot_fetcher(rf, cart_list, lock):
    dict = {}

    with open("inventory.dat", 'r') as f:
        dict = json.load(f)

    for i,v in enumerate(rf):
        x = dict.get(rf[i])
        time.sleep(x[1])
        with lock:
            temp_list = [rf[i], x[0]]
            cart_list.append(temp_list)
