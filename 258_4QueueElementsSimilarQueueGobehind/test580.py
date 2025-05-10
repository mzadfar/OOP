school = []
queue =[[],[],[],[]]
for _ in range(input()):
  arr = raw_input()
  if arr[0]=='E':
    a,s,r=map(str, arr.split())
    s=(int)(s)
    r=(int)(r)
    s-=1
    if queue[s]==[]:
      school.append(s)
    queue[s].append(r)
  else:
    print school[0]+1,queue[school[0]][0]
    del queue[school[0]][0]
    if queue[school[0]]==[]:
      del school[0]