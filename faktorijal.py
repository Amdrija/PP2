def factorial(n):
    p = 1
    i = 1
    while i <= n :
        p *= i
        i += 1
    
    return p


print(factorial(int(input())))