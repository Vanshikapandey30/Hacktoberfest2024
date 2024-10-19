def add_two_numbers(num1, num2):
    temp1=num1
    temp2=num2
    place=1
    total=0
    
    carry=0

    while temp1>0 or temp2>0:
        r1=temp1%10
        r2=temp2%10

        summed_digit=r1+r2+carry

        if summed_digit>9:
            summed_digit%=10
            carry=1
        else:
            carry=0

        total+=summed_digit*place   
        

        place*=10

        temp1//=10
        temp2//=10

    if carry==1:
        return carry*place+total
    else:
        return total
    

num1=int(input())
num2=int(input())

print(add_two_numbers(num1,num2))

