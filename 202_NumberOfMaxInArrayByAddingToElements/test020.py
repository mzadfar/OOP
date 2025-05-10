'''
 * @file test020.py
 * @author M. Z.
 * @brief Multiple number of max elements in an array by adding a constant
 number to elements (stuff them candies in) Input: Length of array, array, and a
 number to distribute Output: An array in which 1 indicats potential max and 0
 indicates otherwise
 * @version 0.1
 * @date 2024-08-04
 *
 * @copyright Copyright (c) 2024
'''

def allExtraCandies(n, candies, extraCandies):
    res = []
    maximum = 0
    for i in range(n):
        if maximum < candies[i]:
            maximum = candies[i]
    for i in range(n):
        if (extraCandies + candies[i]) >= maximum:
            res.append(1)
        else:
            res.append(0)
    return res

n = int(input("Enter length of array: "))
candies = list(map(int, input(f"Enter {n} elements of array: ").split()))
extraCandies = int(input("Enter number of extra candies: "))
out = allExtraCandies(n, candies, extraCandies)
print("Output is: ", out)