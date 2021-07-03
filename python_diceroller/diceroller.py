import random

min = 1
max = 6

rollAgain = "y"

while rollAgain == "y":
    print("Rolling dice...")
    print("The dice have been rolled. The numbers are:")
    print(random.randint(min,max))
    
    rollAgain = input("Roll again? ")

