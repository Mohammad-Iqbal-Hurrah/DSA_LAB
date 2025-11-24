# Topic: Variables, Datatypes, Operators, Input/Output.
# Problems: a) Write a program to calculate the mean, mode and median of three numbers
n1 = float(input("Enter first number: "))
n2 = float(input("Enter second number: "))
n3 = float(input("Enter third number: "))
numbers = [n1,n2,n3]
mean = sum(numbers)/3 #Calculates mean of three numbers==>AVERAGE
numbers.sort() #For median, sequence must be sorted. middle term is median for odd number of terms and average of middle two terms is median for even number of terms.
median = numbers[1] #as there are only three terms and index starts from 0 and ends at 2==> 1 is middle index
#MODE: the term which appears most is the mode
if n1 == n2 or n1 == n3:
    mode = n1
elif n2==n3:
    mode = n2
else:
    mode = "No mode in the series, all numbers are different."
    
print("Mean = ",mean)
print("Median = ",median)
print("Mode = ",mode)