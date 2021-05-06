import random
import string
import subprocess

chars = string.ascii_letters + string.digits

minLength = 8
maxLength = 33      # 32 + 1, just so that max length doesn't cap at 31.

def genPassword(length):
    if length not in range(minLength,maxLength):
        print("Can't generate password: length is out of bounds!")
    else:
        generatedPW = ''.join((random.choice(chars) for i in range(length)))
        print("Your password is: " + generatedPW)
        return generatedPW

def copy(txt):
    # txt = generatedPW
    subprocess.run(['clip.exe'], input=txt.strip().encode('utf-16'), check=True)

passLength = int(input("Enter desired length of password (8-32 characters): "))
password = genPassword(passLength)
copy(password)
print("Password has been copied to clipboard.")
