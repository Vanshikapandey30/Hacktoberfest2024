def is_palindrome(s):
    return s == s[::-1]

def is_symmetrical(s):
    length = len(s)
    mid = length // 2
    if length % 2 == 0:
        return s[:mid] == s[mid:]
    else:
        return s[:mid] == s[mid+1:]

string = "amaama"
if is_symmetrical(string):
    print("The entered string is symmetrical")
else:
    print("The entered string is not symmetrical")

if is_palindrome(string):
    print("The entered string is palindrome")
else:
    print("The entered string is not palindrome")
