# Generate the first 10 terms of the fibonacci series and store ina list 
a = 0
b = 1
n = int(input("Enter the number upto which you want the series: "))
list = [] #Empty list for storing each and every element of the series
while a<=n:
    list.append(a) #stire in a list
    a,b = b,a+b
print(list)