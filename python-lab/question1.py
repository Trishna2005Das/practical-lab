# A) Given a dictionary D, print the support count of each unique values and form a new dictionary with unique values as keys and supoort count as values. Print the new dictionary (D1).Input:D={T1: [E, K, M, N, O,Y],T2: [D,E,K,N,O,Y],T3:[A,E,K,M],T4:[C,K,M,U,Y],T5:[C,E,I,K,O,O]}.Wap to perform the above task.

D={'T1' : ['E', 'K','M', 'N', 'O','Y'],'T2': ['D','E','K','N','O','Y'],'T3':['A','E','K','M'],'T4':['C','K','M','U','Y'],'T5':['C','E','I','K','O','O']}
D1={}
for i in D:
    for j in D[i]:
        if j in D1:
            D1[j]+=1
        else:
            D1[j]=1
print(D1)



