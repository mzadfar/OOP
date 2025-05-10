import sys

def convertBase(numToConvert, base):
    if ((base < 2) or (base >16)):
        print("Enter a number between 2 and 16")
        sys.exit(1)
    ret = ""
    allValues = "0123456789ABCDEF"
    
    while numToConvert !=0:
        value = numToConvert % base
        ret += allValues[value]#str(value)
        numToConvert //= base
    
    if (16 == toBase):
        convertedValue += 'x'
        convertedValue += '0'    
    
    return ret[::-1]

numberToConvert = 60
BASE_2 = 2
print("%d in base %d is %s" % (numberToConvert, BASE_2, convertBase(numberToConvert, BASE_2)))

BASE_8 = 8
print("%d in base %d is %s" % (numberToConvert, BASE_8, convertBase(numberToConvert, BASE_8)))

BASE_16 = 16
print("%d in base %d is %s" % (numberToConvert, BASE_16, convertBase(numberToConvert, BASE_16)))