'''
 * @file test003.py
 * @author M. Z.
 * @brief Maximum value of all subarrays
 * @version 0.1
 * @date 2025-02-14
 *
 * @copyright Copyright (c) 2025
'''

def MaximumSumSubarray(arr, sizeArr):
    if sizeArr == 1:
        return arr[0]
    
    m = sizeArr//2
    leftMaxSumSubarr = MaximumSumSubarray(arr, m)
    rightMaxSumSubarr = MaximumSumSubarray(arr[m:], sizeArr - m)

    sum = 0
    leftSum = rightSum = -float('inf')
    for i in range(m, sizeArr):
        sum += arr[i]
        rightSum = sum if (sum > rightSum) else rightSum

    sum = 0
    for i in range(m-1, -1, -1):
        sum += arr[i]
        leftSum = sum if (sum > leftSum) else leftSum
    
    ret = leftMaxSumSubarr if (leftMaxSumSubarr > rightMaxSumSubarr) else rightMaxSumSubarr

    ret = ret if (ret > (leftSum + rightSum)) else (leftSum + rightSum)
    for i in range(0, sizeArr):
        ret = ret if (ret > arr[i]) else arr[i]
    return ret

arr =[3,-2,5,-1,4]

print("Size of array is", len(arr), "and maximum vaue of all subarrays is", MaximumSumSubarray(arr,len(arr)))

