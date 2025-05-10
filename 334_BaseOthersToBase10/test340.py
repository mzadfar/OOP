import sys 

def convertToDecimal(numToConvert, baseFrom, sizeOfNum):
    toThePowerOf = 0
    ret = 0
    for iChar in numToConvert[::-1]:
        if (iChar.isalpha()): # do not forget () 
            charCode = ord(iChar.lower()) - ord('a') + 10 # do not forget () 
            ret += charCode * pow(baseFrom, toThePowerOf)
        else:
            ret += int(iChar) * pow(baseFrom, toThePowerOf)
        toThePowerOf += 1
    return ret

numberToConvert = "111100"
BASE_2 = 2
print("%s in base %d equals %d in base 10" % (numberToConvert, BASE_2, convertToDecimal(numberToConvert, BASE_2, len(numberToConvert))))

numberToConvert = "74"
BASE_8 = 8
print("%s in base %d equals %d in base 10" % (numberToConvert, BASE_8, convertToDecimal(numberToConvert, BASE_8, len(numberToConvert))))

numberToConvert = "3C"
BASE_16 = 16
print("%s in base %d equals %d in base 10" % (numberToConvert, BASE_16, convertToDecimal(numberToConvert, BASE_16, len(numberToConvert))))





































