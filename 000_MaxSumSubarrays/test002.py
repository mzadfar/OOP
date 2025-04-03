'''
 * @file test002.py
 * @author M. Z.
 * @brief Maximum value of all subarrays
 * @version 0.1
 * @date 2025-02-14
 *
 * @copyright Copyright (c) 2025
'''

def MaximumSumSubarray(arr, sizeArr):
    ret= arr[0]
    for i in range(0, sizeArr):
        ret = ret if (ret > arr[i]) else arr[i]

    if (ret < 0):
        return ret
    
    ret = sum = 0
    for i in range(0, sizeArr):
        if (sum + arr[i]) > 0:
            sum += arr[i]
        else:
            sum =0
        ret = ret if (ret > sum) else sum
    return ret

arr =[3,-2,5,-1,4]

print("Size of array is", len(arr), "and maximum vaue of all subarrays is", MaximumSumSubarray(arr,len(arr)))

