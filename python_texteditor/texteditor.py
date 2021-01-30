import os
from tkinter import *
import tkinter.filedialog
from tkinter.filedialog import askopenfilename
    
root = Tk("Text Editor")
text = Text(root)
text.grid()

def saveas():
    global text
    t = text.get("1.0","end-1c")
    saveLocation = tkinter.filedialog.asksaveasfilename()
    file1 = open(saveLocation,"w+")
    file1.write(t)
    file1.close()

button = Button(root,text="Save",command=saveas)
button.grid()

root.mainloop()
