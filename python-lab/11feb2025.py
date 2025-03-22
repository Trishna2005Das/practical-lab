# def name(first,last):
#     print(first+" "+last)
# name("Trishna","das")

# def cal(a,b,c):
#     if c=='+':
#         print(a+b)
#     elif c=='-':
#         print(a-b)
#     elif c=='*':
#         print(a*b)
#     elif c=='/':
#         print(a/b)
#     else:
#         print(a%b)
        

# c=input("enter operator")
# a=int(input("enter operand"))
# b=int(input("enter operand"))
# cal(a,b,c)

#wap to find fibonacci series of a given no

def fib(n):
    if n<=1:
        return n
    else:
        return (fib(n-1)+fib(n-2))
        
sum=fib(15)
print(sum)

#wap to calculate compound interest-A = P (1 + r/n)^(nt)

def compound_interest(principal,rate,time):
    A=principal*(pow((1+rate/100),time))
    return A

principal=int(input("enter the principal amount"))
rate=float(input("enter the rate"))
time=int(input("enter the time"))
amount=compound_interest(principal,rate,time)
print(amount)