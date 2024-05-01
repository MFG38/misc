todo = []

while True:
    command = input("Command (add, rem, list, sort, exit): ")

    if command == "add":
        entry = input("Insert todo item: ")
        todo.append(entry)
    elif command == "rem":
        i = int(input("Insert index of item to remove: "))
        if i in range(0,len(todo)):
            todo.remove(todo[i])
        else:
            print("ERROR: Index out of bounds")
    elif command == "list":
        for entry in todo:
            print(str(todo.index(entry)), entry)
    elif command == "sort":
        todo.sort()
    elif command == "exit":
        break
    else:
        print("ERROR: Not a recognized command")
