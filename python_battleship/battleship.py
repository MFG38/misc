from random import randint

board = []
for i in range(5):
    board.append(['O'] * 5)

def print_board(board):
    for row in board:
        print(" ".join(row))

def random_row(board):
    return randint(0,len(board) - 1)

def random_col(board):
    return randint(0,len(board[0]) - 1)

ship_row = random_row(board)
ship_col = random_col(board)

for turn in range(10):
    print("Turn", turn + 1)
    print_board(board)
    
    guess_row = int(input("Guess row: "))
    guess_col = int(input("Guess column: "))
    
    if guess_row == ship_row and guess_col == ship_col:
        print("AAAAAAAAA I'M DROWNING gg you found my ship.")
        break
    else:
        if guess_row not in range(0,5) or guess_col not in range(0,5):
            print("ERROR: Guess out of bounds!")
        elif board[guess_row][guess_col] == "X":
            print("ERROR: Nothing already found there!")
        else:
            print("Hah, nope! Not over there!")
            board[guess_row][guess_col] = "X"
        
        if turn == 9:
            print("GAME OVER")

