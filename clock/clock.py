"""
ID: Aryaman Mishra [03aryam1]
LANG: PYTHON3
TASK: clock
"""

"""
NAME                 :    Aryaman Mishra
GROUP                :    Binary
LAST MODIFIED        :    April 11 2023
PROBLEM ID           :    Clock
PROBLEM DESCRIPTION  :    Print given time in written English
PEOPLE WHO I HELPED  :    N/A
PEOPLE WHO HELPED ME :    N/A
"""

# Declare USACO I/0
fin = open("clock.in", "r")
fout = open("clock.out", "w")

# Function that converts Arabic Num to English
def numCalc(intNum):

    holder = ""
    strNum = str(intNum)

    if (intNum > 20):
        print(intNum)
        first, second = [x for x in strNum]
        first += "0"
        holder = hourWord[int(first)] + "-" + hourWord[int(second)]
    else:
        holder = hourWord[intNum]

    return holder

# Dictionary which holds all num to English conversions
hourWord = {
    1: "one",
    2: "two",
    3: "three",
    4: "four",
    5: "five",
    6: "six",
    7: "seven",
    8: "eight",
    9: "nine",
    10: "ten",
    11: "eleven",
    12: "twelve",
    13: 'thirteen',
    14: 'fourteen',
    15: 'fifteen',
    16: "sixteen",
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'thirty',
    40: 'forty',
    50: 'fifty'
}

# Take in inputs
inStr = fin.read()

# Store input as hour and minute
hour, minute = [int (x) for x in inStr.split(":")]

# Do special cases first
if minute == 0:
    fout.write(str(numCalc(hour) + " o'clock" ).capitalize())
elif minute == 15:
    fout.write(str("Quarter past " + numCalc(hour)).capitalize())
elif minute == 30:
    fout.write(str(numCalc(hour) + " thirty").capitalize())
elif minute == 45:
    if (hour == 12):
        hour = 0
    fout.write(str("Quarter to " + numCalc(hour+1)).capitalize())

# If its not a special case just print normal num
else:
    # If less then 45 minutes print normal
    if (minute < 45):
            print (minute)
            fout.write(str(numCalc(hour) + " " + numCalc(minute) ).capitalize())

    # If more then do " This minute to next hour"
    else:
        if hour == 12:
            hour = 0
        fout.write(str(numCalc(60-minute) + " to " + numCalc(hour+1)).capitalize())

# Add new line/ exit code
fout.write('\n')
