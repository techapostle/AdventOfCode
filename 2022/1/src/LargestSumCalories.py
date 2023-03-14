# declare list to hold sum of calories held by each elf
# declare variable to hold each line of file
# declare variable to hold the largest sum of calories 
# the file name is "input.txt"
# try to open the file, if it fails, print an error message and exit
# read each line of the file and add it to a temporary variable
# when you encounter a new line, store the value of the temporary variable in the list as a new element
# repeat until the end of the file
# once the file has been read, close the file
# find the largest sum of calories in the vector
# print the largest sum of calories

# Path: src/LargestSumCalories.py
caloriesSum = []
line = ""
largestSum = 0
# the file name is "input.txt"
try:
    f = open("input.txt", "r")
except:
    print("Error: could not open file")
    exit()
# read each line of the file and add it to a temporary variable
for x in f:
    line += x
    # when you encounter a new line, store the value of the temporary variable in the list as a new element
    if x == "\n": 
        caloriesSum.append(int(line))
        line = ""
# find the largest sum of calories in the vector
for x in caloriesSum:
    if x > largestSum:
        largestSum = x
# print the largest sum of calories
print(largestSum)