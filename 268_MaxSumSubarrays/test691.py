def max_subarray(n,arr):
  max =arr[0]
  sum =0
  for i in range(0,n):
    sum+=arr[i]
    if (max<sum):
      max=sum
    if sum<0:
      sum=0
  return max
n=input()
arr = map(int,raw_input().split())
out1=max_subarray(n,arr)
print out1