def findSquare(num):
 
    # base case
    if num < 2:
        return num
 
    # convert the number to positive if it is negative
    num = abs(num)
 
    # drop last bit from num (divide it by 2)
    i = num >> 1
 
    # if num is odd
    if (num & 1) == 1:
        return (findSquare(i) << 2) + (i << 2) + 1
 
    # if num is even
    else:
        return findSquare(i) << 2
 
n = 8
if __name__ == '__main__':
    print(findSquare(n))
 