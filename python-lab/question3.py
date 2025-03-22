# C) Remove the key and values from dictionary D1, that does not satisfy minimum support count. (Minimum Support count=3)
D1={'E': 4, 'K': 5, 'M': 3, 'N': 2, 'O': 4, 'Y': 3, 'D': 1, 'A': 1, 'C': 2, 'U': 1, 'I': 1}
D3={}
for i in D1:
    if D1[i]>=3:
        D3[i]=D1[i]
print(D3)
