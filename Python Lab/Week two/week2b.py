# Convert temperature dataset from celsius to faarenhite
celsius = [25.3, 26.7, 24.8, 27.5, 28, 26.1, 25.9, 27.3, 29.2, 30.1, 27.7, 27.9, 26.8, 25.5, 29.4]
farenhite = [(temp*9/2)+32 for temp in celsius]
print("Day\tCelsius\tFarenhite")
for i in range(len(celsius)):
    print(f"{i+1}\t{celsius[i]:.1f}\t{farenhite[i]:.2f}")