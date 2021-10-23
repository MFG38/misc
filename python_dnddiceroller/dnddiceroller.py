from random import randint

def roll(roll):
    rolling = []
    
    try:
        for x in range(int(roll.split('d')[0])):
            rolling.append(randint(1,int(roll.split('d')[1])))
    except Exception as err:
        print(f'Fault encountered: {err}')
    
    print(f'You rolled {"+".join(str(x) for x in rolling)} for a total of {sum(rolling)}.')

while True:
    print("Input your roll in xdy format, where x is the number of dice")
    print("and y is the number of sides on each die.")
    print("")
    r = input("(WAITING FOR INPUT) Roll: ")
    roll(r)

