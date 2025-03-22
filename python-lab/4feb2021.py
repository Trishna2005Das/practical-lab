#input in list 10 elements of different datatypes
# lst=[ 9,3+5j,"hello",True,3.5,(1,2,3),[1,2,3]]
# lst.insert(4,"ram")
# print(lst)
# lst.insert(7,"3+5j")
# print(lst)
# #pop
# #remove
# lst.pop(1)
# print(lst)
# lst.remove("ram")
# print(lst)
# lst.clear()
# lst1=["ram",[50,-207],[2+5J,70],[27,-50.0,7+2J]]
# print(lst1[3][1D1={'E': 4, 'K': 5, 'M': 3, 'N': 2, 'O': 4, 'Y': 3, 'D': 1, 'A': 1, 'C': 2, 'U': 1, 'I': 1}
#sort D1 in descending order
D2={}
D2=dict(sorted(D1.items(), key=D1.get, reverse=True))])
# print(lst1[2][0])
# a=[]
# a=lst1.copy()
# print(a)
# print(lst.count("ram"))
# tup=("ram",20,-207,2+5j,75)
# tup1=(1,2,3)
# #skip first and last element and show rest element in the display
# a=list(tup)
# print(tup[1:4])
# a.pop(2)
# print(a)
# a.remove("ram")
# print(a)
# a.extend((1,2,3))
# print(a)
# a.append(2)
# print(a)
# a.insert(4,10)
# print(a)
# print(a.index(20))
# print(tup,tup1)
set1={1,2,7,True,0,'ram',False,2,-7.0,2+5j}
set2={70,7,2,True,'hani',-20.0}
print(set1)
print(set2)
set1.union(set2)
set1.intersection(set2)
print(set1|set2)
print(set1&set2)
print(set1-set2)
print(set1^set2)
abc={"branch":"cse",
     "name":"trish",
     "roll":55}
print(type(abc))
print(len(abc))
for keys in abc:
    print(keys)
#print keys and values of dict abc
for keys in abc:
    print(keys,abc[keys])
print(abc.keys())
print(abc.values())
print(abc.items())
print(abc.get("name"))
abc["name"]="trishna"
print(abc)
abc["branch"]="cse"
#add more keys and values to dictionary abc
abc.update({"branch":""})
#is dictionary ordered or unordered- dict is unordered
def func(s):
    print(s+" welcome to class")
s="ram"
func(s)
#wap to find common elements among two sets
#wap to check whether a given key already exists in the dictionary or not
#wap using nested list and use list slicing to show the lsit slicing odd indexes 
#wap to swap all the elements in a list that contains 10 elements
#wap to chekc whether the index is prime or not if prime store the index in a separate list 
#wap the inverse the keys and values of a dict if multiple keys have same values store them in a list
#wap to convert a list to a set and remove duplicates
