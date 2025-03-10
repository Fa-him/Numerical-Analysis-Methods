n=int(input("Enter number of equation: "))
v=[]
print("Enter the co-efficients: ")
for i in range(n):
    v.append(list(map(float, input().split())))
    
for i in range(n):
    for j in range(i+1, n):
        r=v[j][i]/v[i][i]
        for k in range(n+1):
            v[j][k]-=r*v[i][k]

print("\nRoots are: ")
ar=[0]*n
for i in range(n-1, -1, -1):
    sum_val=0
    
    for j in range(i + 1, n):  
        sum_val += v[i][j] * ar[j]

    ar[i]=(v[i][n]-sum_val)/v[i][i]

for i in range(n):
    print(f"x[{i+1}]={ar[i]}")
