import random

def readstring(prompt):
    return input(prompt)

def readinteger(prompt):
    line = readstring(prompt)
    while not line.isdigit():
        print("enter a whole number")
        line = readinteger(prompt)
    return int(line)

target = random.randrange(1, 10)
guess = readinteger("guess a number 1 to 10: ")

while(guess != target):
    if(guess > target):
        print("your guess is higher than the target")
        guess = readinteger("guess a number: ")
    elif(guess < target):
        print("your guess is lesser than the target")
        guess = readinteger("guess a number: ")
    else:
        print("your guess is not a number")
        guess = readinteger("guess a number: ")

print("got it")
