'''
 * @file test001.py
 * @author M. Z.
 * @brief Maximum value of all subarrays:Time complexity O(n^2)
 * @version 0.1
 * @date 2025-02-14
 *
 * @copyright Copyright (c) 2025
'''

def MaximumSumSubarray(arr, sizeArr):
    ret= -float('inf')
    for startIndex in range(0, sizeArr):
        sum = 0
        for subArrSize in range(1, sizeArr+1):
            if ((subArrSize + startIndex) > sizeArr):
                break
            sum += arr[startIndex + subArrSize -1]
            ret = sum if (sum > ret) else ret
    return ret

arr =[3,-2,5,-1,4]

print("Size of array is", len(arr), "and maximum vaue of all subarrays is", MaximumSumSubarray(arr,len(arr)))

