"""
ID: Aryaman Mishra [03aryam1]
LANG: PYTHON3
TASK: subset
"""

"""
// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 2 2023
// PROBLEM ID           :    Subset
// PROBLEM DESCRIPTION  :    Calculate all subset of a number
//                           which add up to each other
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A

"""
# Declare USACO Input/Output
fin = open("subset.in", "r")
fout = open("subset.out", "w")

# Declare Variables
product = 0
numSet = int(fin.read())

print("\n")
# Calculate Sum
for x in range(1, numSet+1):
    sum += x

# If Invalid, Stop Code
if sum % 2 != 0:
    fout.write(str(0) + "\n")
    exit()


sum /= 2
sum = int(sum)

# Make list
mainList = list()
storeList = list()
for x in range(0, sum*sum):
    mainList.append(0)
    storeList.append(0)


# Intialize Variables
mainList[0] = 1
storeList[0] = 1
curMax = 1
runner = 1

# Run Through Code
for row in range(1, numSet+1):
    for col in range(0, sum):

        curMax = max(row+col+1, curMax)
        mainList[row+col] += storeList[col]

    runner = min(curMax, sum-numSet+1)
    for x, y in enumerate(mainList):
        storeList[x] = y

# Output Results
fout.write(str(int(mainList[sum]/2)) + "\n")
fout.close()

