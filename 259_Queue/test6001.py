n = int(raw_input())
stack =[]

for i in range(n):
  arr = map(int, raw_input().split())
  stack.append(arr[1:])
q = int(raw_input())
first_min=[stack[0][0]]
for i in range(1,len(stack[0])):
  first_min.append(min(first_min[-1], stack[0][i]))

for _in range(q):
  inp=map(int,raw_input().split())
  if inp[0] ==0:
    stack[inp[1]-1].pop()
    if inp[1]==1:
      first_min.pop()
  elif inp[0]==1:
    stack[inp[1]-1].append(inp[2])
    if inp[1]==1:
      first_min.append(min(first_min[-1], inp[2]))
  else:
    chk = 0
    if stack[0]==[]:
      print "NO"
      continue
    key=first_min[-1]
    for i in range(1,n):
      if stack[i]==[] or key>stack[i][-1]:
        chk=1
        break
      key = stack[i][binarySearch(stack[i],key)]
    if chk==0:
      print "YES"
    else:
      print "NO"