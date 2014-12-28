# text dollar soln in py for code eval by steven a dunn

import sys

def ones_word(digit):
    return {
        '1': "One",
        '2': "Two",
        '3': "Three",
        '4': "Four",
        '5': "Five",
        '6': "Six",
        '7': "Seven",
        '8': "Eight",
        '9': "Nine",
        '0': None,
    }[digit]

def tens_word_teens(last_digit):
    return {
        '0': "Ten",
        '1': "Eleven",
        '2': "Twelve",
        '3': "Thirteen",
        '4': "Fourteen",
        '5': "Fifteen",
        '6': "Sixteen",
        '7': "Seventeen",
        '8': "Eighteen",
        '9': "Nineteen",
    }[last_digit]

def tens_word(first_digit, last_digit):
    return {
        '9': "Ninety",
        '8': "Eighty",
        '7': "Seventy",
        '6': "Sixty",
        '5': "Fifty",
        '4': "Forty",
        '3': "Thirty",
        '2': "Twenty",
        '1': tens_word_teens(last_digit),
        '0': None,
    }[first_digit]

def get_hundred_millions_word(number):
    text = str(number)
    if get_hundreds_word(text[0:3]):
        return get_hundreds_word(text[0:3]) + "Million" + get_hundred_thousands_word(text[3:])
    else:
        return get_thousands_word(text[3:])

def get_ten_millions_word(number):
    text = str(number)
    if tens_word(text[0], text[1]):
        return tens_word(text[0], text[1]) + "Million" + get_hundred_thousands_word(text[2:])
    else:
        return get_hundred_thousands_word(text[2:])

def get_millions_word(number):
    text = str(number)
    if ones_word(text[0]):
        return ones_word(text[0]) + "Million" + get_hundred_thousands_word(text[1:])
    else:
        return get_hundred_thousands_word(text[1:])

def get_hundred_thousands_word(number):
    text = str(number)
    if get_hundreds_word(text[0:3]):
        return get_hundreds_word(text[0:3]) + "Thousand" + get_hundreds_word(text[3:])
    else:
        return get_hundreds_word(text[3:])

def get_ten_thousands_word(number):
    text = str(number)
    if get_tens_word(text[0:2]):
        return get_tens_word(text[0:2]) + "Thousand" + get_hundreds_word(text[2:])
    else:
        return get_hundreds_word(text[2:])

def get_thousands_word(number):
    text = str(number)
    if ones_word(text[0]):
        return ones_word(text[0]) + "Thousand" + get_hundreds_word(text[1:])
    else:
        return get_hundreds_word(text[1:])

def get_hundreds_word(number):
    text = str(number)
    if ones_word(text[0]):
        return ones_word(text[0]) + "Hundred" + get_tens_word(text[1:3])
    else:
        return get_word(text[1:3])

def get_tens_word(number):
    text = str(number)
    number = int(number)
    result = ""

    if number == 0:
        return result
    elif number < 10:
        number = int(number)
        text = str(number)
        result += ones_word(text[0])
    elif number < 20:
        result += tens_word(text[0], text[1])
    else:
        result += tens_word(text[0], text[1])
        if ones_word(text[1]):
            result += ones_word(text[1])
    return result

def get_word(number):
    text = str(number)
    text_length = len(text)

    first_digit = text[0]
    last_digit = text[text_length - 1]

    result = ""

    if (text_length == 2):
        if tens_word(first_digit, last_digit):
            result += tens_word(first_digit, last_digit)
        if ones_word(last_digit):
            result += ones_word(last_digit)
        return result

    if(text_length != 2 or first_digit != 1):
        return ones_word(last_digit);

f = open(sys.argv[1], 'r')

for line in f:
    number = long(line)

    text = ""
    if number < 100:
        text += get_tens_word(number)
    elif number < 1000:
        text += get_hundreds_word(number)
    elif number < 10000:
        text += get_thousands_word(number)
    elif number < 100000:
        text += get_ten_thousands_word(number)
    elif number < 1000000:
        text += get_hundred_thousands_word(number)
    elif number < 10000000:
        text += get_millions_word(number)
    elif number < 100000000:
        text += get_ten_millions_word(number)
    else:
        text += get_hundred_millions_word(number)

    text += "Dollars"
    print text

f.close()