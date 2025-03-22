# A) Given a dictionary D, print the support count of each unique values and form a new dictionary with unique values as keys and supoort count as values. Print the new dictionary (D1).
# Input:
# D={
# T1: [E, K, M, N, O,Y],
# T2: [D,E,K,N,O,Y],
# T3:[A,E,K,M],
# T4:[C,K,M,U,Y],
# T5:[C,E,I,K,O,O]
# }


# B) Considering the above support count of dictionary D1, sort the dictionary in decreasing order.
# C) Remove the key and values from dictionary D1, that does not satisfy minimum support count. (Minimum Support count=3)
# D) Given the updated dictionary D1 that satisfy minimum support count and the original Dictionary D, delete the values from D which is not present in D1. Now, print the dictionary D.
# D={
# T1: [E, K, M, N, O,Y],
# T2: [D,E,K,N,O,Y],
# T3:[A,E,K,M],
# T4:[C,K,M,U,Y],
# T5:[C,E,I,K,O,O]
# }
# D1={
# K:5, 
# E:4, 
# M:3, 
# O:3,
# Y:3
# }