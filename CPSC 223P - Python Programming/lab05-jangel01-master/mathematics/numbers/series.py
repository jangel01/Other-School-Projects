def sum(*, list):
    result = 0
    for x in list:
        result = result + x;

    return result

def average(*, list):
    sum = 0;

    for x in list:
        sum = sum + x;

    result = sum / len(list)

    return result
