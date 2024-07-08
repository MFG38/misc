def wtf(a: bool, b: bool, c: bool):
    if a and b and c:
        return True
    elif not a and b and c:
        return True
    elif a and not b and c:
        return False
    elif a and b and not c:
        return False
    elif not a and not b and c:
        return True
    elif not a and b and not c:
        return False
    elif a and not b and not c:
        return True
    elif not a and not b and not c:
        return False

print(wtf(True, False, False))
print(wtf(False, True, False))
print(wtf(False, False, True))
print(wtf(True, True, False))
print(wtf(True, False, True))
print(wtf(False, True, True))
print(wtf(True, True, True))
print(wtf(False, False, False))
