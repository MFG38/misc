import random

responses = [
    "Not likely.",
    "Perhaps.",
    "Definitely not.",
    "That would be a very strong maybe.",
    "Probably not.",
    "Likely yes.",
    "Probably.",
    "Definitely.",
    "Wouldn't count on it.",
    "You can count on it.",
    "Ask again tomorrow.",
    "0x098123a0: Unexpected error processing question."
]

while True:
    q = input("What do you wish to know? (Yes/No questions only!) ")
    print(random.choice(responses))
