# A function that calculates the factorial of a give number using recursion
def factorial_recursion(number):
    if number == 0 or number == 1:
        return 1
    elif number < 0 :
        return "Enter a number thats greater or equal to zero."
    else:
        return number * factorial_recursion(number - 1)
