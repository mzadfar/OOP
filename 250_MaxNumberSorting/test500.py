for _ in range(input()):
  n,l = map(int, raw_input().split())
  arr = map(int, raw_input().split())
  sb = 0
  pv = [0 for i in range(30)]
  vis = [0 for i in range(30)]
  for i in range(n):
    b = format(arr[i], "b")
    x = len(b)
    j =x-1
    while j>=0
      pv[x-j-1] +=int(b[j])*pow(2,x-j-1)
      if int(b[j]) ==1;
        sb+=vis[x-j-1]
        vis[x-j-1] = 0
      j-=1
  if sb< l:
    print "-1"
    continue
  pv.sort(reverse = True)
  res=1
  for i in range(sb):
    if l<= 0:
      break
    if pv[i] !=pv[i+1]:
      l-=1
    else:
      count=0
      while i!=sb-1 and pv[i]==pv[i+1]:
        count+=1
        i+=1
      count +=1
      if l<count:
        res *=ncr (count,l)
        break
      l-=count
  print res
