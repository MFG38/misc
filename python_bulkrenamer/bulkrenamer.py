import os
import re

wd = os.getcwd()

def renameBulk(path, pattern, replacement):
    for filename in os.listdir(wd):
        if re.search(pattern, filename):
            renameTarget = re.sub(pattern, replacement, filename)
            newName = os.path.join(path, renameTarget)
            oldName = os.path.join(path, filename)
            os.rename(oldName, newName)

#print("Working directory is " + format(wd))
lookFor = input("Enter pattern to look for: ")
replaceWith = input("Enter replacement pattern: ")
renameBulk(wd, lookFor, replaceWith)
