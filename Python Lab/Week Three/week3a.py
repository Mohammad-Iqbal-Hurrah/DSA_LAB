 # W.A.P to count how many values in a dataset are above and below average
list = [10,20,30,40,50]
sum = 0
below = 0
above = 0
for i in range(0,len(list)):
    sum = sum+list[i]
average = int(sum / len(list))
print("Average = ",average)
print("Values below average: ")
for i in range(0,len(list)):
    if list[i]<average:
        print(list[i])
        below+=1
    else:
        continue
print("Total values below average = ",below)
print("Values above average: ")
for i in range(0,len(list)):
    if list[i]>average:
        print(list[i])
        above+=1
    else:
       continue
print("Total values above average = ",above)