import re

def isValidEmail(email):
    pattern = r'^[\w\.-]+@[\w\.-]+\.\w+'

    if re.match(pattern, email):
        return True
    else:
        return False
get_user_input = input("Enter Email Address: ")

if isValidEmail(get_user_input):
    print('Valid email Address \n')
else:
    print('Invalid Email Address \n')