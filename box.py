import tkinter as tk 

root = tk.Tk()

root.title("Simple GUI")
root.geometry("500x500")

# Step 3: Create and pack a label widget
label = tk.Label(root, text="Enter your name:")
label.pack()

# Step 4: Create and pack an entry widget
entry = tk.Entry(root)
entry.pack()

#BUTTON 
btn = tk.Button(root,text="Greet")
btn.pack()



root.mainloop()