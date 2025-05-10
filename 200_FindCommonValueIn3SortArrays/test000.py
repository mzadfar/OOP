'''
 * @file test000.py
 * @author M. Z.
 * @brief Intersection of 3 sorted arrays: Input: 3 sorted arrays
 Output: a sorted array of common elements among 3 input arrays
 * @version 0.1
 * @date 2024-08-03
 *
 * @copyright Copyright (c) 2024
 '''

def intersect_array(n1, n2, n3, arr1, arr2,arr3):
    x_loc = 0
    y_loc = 0
    z_loc = 0
    res = []
    while x_loc != n1 and y_loc != n2 and z_loc != n3:
        x = arr1[x_loc]
        y = arr2[y_loc]
        z = arr3[z_loc]
        if x == y and y == z:
            res.append(x)
            x_loc += 1
            y_loc += 1
            z_loc += 1
        elif x <= y and x <= z:
            x_loc += 1
        elif y <= x and y <= z:
            y_loc += 1
        else:
            z_loc =+ 1
    return res

n1 = int(input("What is the length of arr1: \n"))
n2 = int(input("What is the length of arr2: \n"))
n3 = int(input("What is the length of arr3: \n"))

arr1 = list(map(int, input(f"Enter {n1} elements of first array: ").split()))
arr2 = list(map(int, input(f"Enter {n2} elements of second array: ").split()))
arr3 = list(map(int, input(f"Enter {n3} elements of third array: ").split()))

print(f"\nYou entered {n1} numbers for arr1: \n", ' '.join(map(str, arr1)))
print(f"\nYou entered {n2} numbers for arr2: \n", ' '.join(map(str, arr2)))
print(f"\nYou entered {n3} numbers for arr3: \n", ' '.join(map(str, arr3)))

out = intersect_array(n1, n2, n3, arr1, arr2, arr3)
print("Intersect of 3 arrays is: ", out)