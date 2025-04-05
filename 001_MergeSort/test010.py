'''
 * @file test010.py
 * @author M. Z.
 * @brief Sort an array by splitting it into 2 arrays, and merge it back into 1
 * array
 * @date 2025-02-18
 *
 * @copyright Copyright (c) 2025
'''
import sys

def Merge(arr, leftArr, leftArrSize, rightArr, rightArrSize):
    i = j = k = 0
    while ((i < leftArrSize) and (j < rightArrSize)):
        if (leftArr[i] < rightArr[j]):
            arr[k] = leftArr[i]
            k += 1
            i += 1
        else:
            arr[k] = rightArr[j]
            k += 1
            j += 1
    while (i < leftArrSize):
        arr[k] = leftArr[i]
        k += 1
        i += 1
    while (j < rightArrSize):
        arr[k] = rightArr[j]
        k += 1
        j += 1
    return arr

def MergeSort(arr, arrSize):
    if (arrSize < 2):
        return
    
    arrMidSize = arrSize // 2

    leftArr = [0] * arrMidSize
    for i in range(0,arrMidSize):
        leftArr[i] = arr[i]

    rightArr = [0] * (arrSize - arrMidSize)
    for i in range(0, arrSize - arrMidSize):
        rightArr[i] = arr[arrMidSize + i]
    
    MergeSort(leftArr, arrMidSize)
    MergeSort(rightArr, arrSize - arrMidSize)
    Merge(arr, leftArr, arrMidSize, rightArr, arrSize - arrMidSize)    
    return arr


arr= [6, 2, 3, 1, 9, 10, 15, 13, 12, 17]
MergeSort(arr, len(arr))
print("Sorted array: ", *arr)