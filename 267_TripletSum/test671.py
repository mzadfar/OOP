def no_of_triplets(n,arr):
  d={}
  for i in range(n):
    d[-arr[i]]=i
  count =0
  for i in range(n-1):
    for j in range(i+1,n):
      if ((arr[i]+arr[j]) in d) and d[arr[i]+arr[j]]!=i and d[arr[i]+arr[j]]!=j:
        count+=1
  count =count//3
  return count
  pass

n=input()
arr = map(int,raw_input().split())
out1=no_of_triplets(n,arr)
print out1