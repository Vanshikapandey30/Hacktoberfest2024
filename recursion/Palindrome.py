checkstr=input("enter any string: ")
length=len(checkstr)
c=length/2
if checkstr==checkstr[::-1]:
    print ("it is a palindrome")
else:
    print ("it is not a palindrome")
