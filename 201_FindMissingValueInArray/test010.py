'''
 * @file test010.py
 * @author M. Z.
 * @brief Find missing number:
 Input: an array with n-1 length, and elements between 1 to n with one missing
 number Output: the missing number
 * @version 0.1
 * @date 2024-08-03
 *
 * @copyright Copyright (c) 2024
 '''

def missing_no(n, arr):
    res = n * (n + 1) / 2
    array_sum = 0
    for i in range (n - 1):
        array_sum =array_sum + arr[i]
    res = res - array_sum
    return (int)(res)

n = int(input("Enter the number n: "))
arr = list(map(int, input(f"Enter {n - 1} elements: ").split()))

out = missing_no(n, arr)
print("missing number is: ", out)