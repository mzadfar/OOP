def spiralMatrix(A):
    spiralOrder = []
    maxCol = len(A[0])-1
    maxRow = len(A)-1
    minCol = 0
    minRow = 0

    stateRight = 0
    stateLeft = 1
    stateDown = 2
    stateUp = 3

    i = 0
    j = 0

    currentState = stateRight

    totalTerms = (maxCol + 1) * (maxRow + 1)

    while len(spiralOrder) < totalTerms:
        if currentState == stateRight:
            if j < maxCol:
                spiralOrder.append(A[i][j])
                j += 1
            elif minCol >= maxCol:
                spiralOrder.append(A[i][j])
            else:
                currentState = stateDown
                minRow += 1

        elif currentState == stateDown:
            if i < maxRow:
                spiralOrder.append(A[i][j])
                i += 1
            else:
                currentState = stateLeft
                maxCol -= 1

        elif currentState == stateLeft:
            if j > minCol:
                spiralOrder.append(A[i][j])
                j -= 1
            else:
                currentState = stateUp
                maxRow -= 1

        elif currentState == stateUp:
            if i > minRow:
                spiralOrder.append(A[i][j])
                i -= 1
            else:
                currentState = stateRight
                minCol += 1        
            
    return spiralOrder

A = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]  
B = [
    [1,2,3,4],
    [14,15,16,5],
    [13,20,17,6],
    [12,19,18,7],
    [11,10,9,8],
] 
C = [
    [1,2,3,4,5],
    [14,15,16,17,6],
    [13,20,19,18,7],
    [12,11,10,9,8],
] 
print(spiralMatrix(C))