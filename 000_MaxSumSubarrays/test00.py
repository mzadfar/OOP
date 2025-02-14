'''
 * @file test00.py
 * @author M. Z.
 * @brief Maximum value of all subarrays:Time complexity O(n^2)
 * @version 0.1
 * @date 2025-02-14
 *
 * @copyright Copyright (c) 2025
'''

def MaximumSumSubarray(arr, sizeArr):
    ret= -float('inf')
    for subArrSize in range(1, sizeArr + 1):
        for startIndex in range(0, sizeArr):
            if (startIndex + subArrSize) > sizeArr:
                break
            sum = 0
            for i in range (0, startIndex + subArrSize):
                sum += arr[i]
            ret = sum if (sum > ret) else ret
    return ret

arr =[3,-2,5,-1,4]

print("Size of array is", len(arr), "and maximum vaue of all subarrays is", MaximumSumSubarray(arr,len(arr)))

