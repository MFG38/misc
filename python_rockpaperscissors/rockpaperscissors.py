import random

validPhrases = ["rock", "paper", "scissors"]

playerChoice = ""
cpuChoice = ""

def get_result():
    # Draw condition
    if playerChoice == cpuChoice:
        print("DRAW")
    
    # Lose conditions
    elif playerChoice == "rock" and cpuChoice == "paper":
        print("YOU LOSE")
    elif playerChoice == "paper" and cpuChoice == "scissors":
        print("YOU LOSE")
    elif playerChoice == "scissors" and cpuChoice == "rock":
        print("YOU LOSE")
    
    # Win conditions
    elif playerChoice == "scissors" and cpuChoice == "paper":
        print("YOU WIN")
    elif playerChoice == "rock" and cpuChoice == "scissors":
        print("YOU WIN")
    elif playerChoice == "paper" and cpuChoice == "rock":
        print("YOU WIN")
    
while True:
    h = input("Rock, paper or scissors? Input your choice: ")
    
    if h not in validPhrases:
        print("ERROR: Input not valid!")
    else:
        playerChoice = h
        print(f"You play {playerChoice}.")
        cpuChoice = random.choice(validPhrases)
        print(f"CPU plays {cpuChoice}.")
        
        get_result()
        print("")

