# D) Given the updated dictionary D1 that satisfy minimum support count and the original Dictionary D, delete the values from D which is not present in D1. Now, print the dictionary D.D={T1: [E, K, M, N, O,Y],T2: [D,E,K,N,O,Y],T3:[A,E,K,M],T4:[C,K,M,U,Y],T5:[C,E,I,K,O,O]}
#D1={K:5, E:4, M:3, O:3,Y:3}
D={'T1' : ['E', 'K','M', 'N', 'O','Y'],'T2': ['D','E','K','N','O','Y'],'T3':['A','E','K','M'],'T4':['C','K','M','U','Y'],'T5':['C','E','I','K','O','O']}
D3={'E': 4, 'K': 5, 'M': 3, 'O': 4, 'Y': 3}

for i in D3:
    for j in D:
        if i in j:
            D[j].remove(i)

print(D)




