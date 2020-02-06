def median(list):
    if len(list)%2 == 0:
        median = (list[(len(list)//2)]+list[(len(list)//2-1)])/2
    else:
        median = list[(len(list)//2)]
    return(median)

N = int(input())
X = list(map(int, input().strip().split(' ')))
F = list(map(int, input().strip().split(' ')))
S=[]
for i in range(len(X)):
    S += [X[i]] * F[i]
S.sort()
Q1, Q2, Q3 = median(S[:(sum(F)//2)]), median(S), median(S[(sum(F)//2):] if len(S)%2==0 else S[(1+sum(F)//2):])

print("{0:0.1f}".format(Q3-Q1))