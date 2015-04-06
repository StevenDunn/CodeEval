# text to number py2 soln for code eval by steven a dunn

import sys

negative = False

def combine_results(sub_result, prior_sub_result):
    sub_len = len(str(sub_result))
    prior_len = len(str(prior_sub_result))

    while (prior_len <= sub_len):
        prior_sub_result *= 10
        prior_len += 1

    return prior_sub_result + sub_result

def is_negative (word):
    global negative
    if word == "negative":
        negative = True
    return negative

def is_magnitude (word, converted_value):
    result = True
    if (word == "hundred"):
        converted_value = 100
    elif (word == "thousand"):
        converted_value = 1000
    elif (word == "million"):
        converted_value = 1000000
    else:
        result = False
    return [result, converted_value]

def is_digit (word, converted_value):
    result = True
    if word == "one":
        converted_value = 1
    elif word == "two":
        converted_value = 2
    elif word == "three":
        converted_value = 3
    elif word == "four":
        converted_value = 4
    elif word == "five":
        converted_value = 5
    elif word == "six":
        converted_value = 6
    elif word == "seven":
        converted_value = 7
    elif word == "eight":
        converted_value = 8
    elif word == "nine":
        converted_value = 9
    elif word == "ten":
        converted_value = 10
    elif word == "eleven":
        converted_value = 11
    elif word == "twelve":
        converted_value = 12
    elif word == "thirteen":
        converted_value = 13
    elif word == "fourteen":
        converted_value = 14
    elif word == "fifteen":
        converted_value = 15
    elif word == "sixteen":
        converted_value = 16
    elif word == "seventeen":
        converted_value = 17
    elif word == "eighteen":
        converted_value = 18
    elif word == "nineteen":
        converted_value = 19
    elif word == "twenty":
        converted_value = 20
    elif word == "thirty":
        converted_value = 30
    elif word == "forty":
        converted_value = 40
    elif word == "fifty":
        converted_value = 50
    elif word == "sixty":
        converted_value = 60
    elif word == "seventy":
        converted_value = 70
    elif word == "eighty":
        converted_value = 80
    elif word == "ninety":
        converted_value = 90
    else:
        result = False
    return [result, converted_value]

def text_to_number (words):
    global negative
    result = 0
    sub_result = 0
    prior_sub_result = 0
    converted_value = 0
    negative = False

    for word in words:
        is_digit_val, digit_converted_value = is_digit(word, converted_value)
        is_magnitude_val, magnitude_converted_value = is_magnitude(word, converted_value)

        if is_digit_val:
            sub_result += digit_converted_value

        elif is_magnitude_val:
            if sub_result == 0:
                sub_result = prior_sub_result * magnitude_converted_value
                result -= prior_sub_result
            else:
                sub_result *= magnitude_converted_value

                if sub_result > prior_sub_result and prior_sub_result != 0:
                    result -= prior_sub_result
                    sub_result = combine_results(sub_result, prior_sub_result)

            result += sub_result
            prior_sub_result = sub_result
            sub_result = 0

        elif is_negative(word):
            negative = True

    if sub_result != 0:
        result += sub_result

    if negative:
        result *= -1

    return result

f = open(sys.argv[1], 'r')
for line in f:
    print (text_to_number(line.rstrip().split(" ")))
f.close()