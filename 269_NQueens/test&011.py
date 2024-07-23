def gen(n,row_count,col,d1,d2,count):
  if row_count ==n:
    return count +1
  for j in range(n):
    if (j in col) or ((row_count-j) in d1) or ((row_count+j) in d2):
      continue
    col.add(j)
    d1.add(row_count-j)
    d2.add(row_count+j)
    count = gen(n, row_count+1, col, d1,d2,count)
    d2.remove(row_count+j)
    d1.remove(row_count-j)
    col.remove(j)
  return count

def solve (n):
  return gen(n,0,set(),set(),set(),0)
n=input()
out1 = solve(n)
print out1