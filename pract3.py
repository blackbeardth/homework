"""
Practical 3

Write a python program to find nth term 
of the fibonnaci sequence and its factorial. 
Return the result as a list.

Written by Chirag Wadhwa for the University of Delhi
"""


def fibonacci(n):
    assert n > 0, "invalid input"
    if n == 1 or n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


def factorial(n):
    assert n >= 0, "invalid input"
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)


def fibonacciAndFactorial(n):
    return [fibonacci(n), factorial(n)]


def main():
    n = int(input("Enter term: "))
    f = fibonacciAndFactorial(n)
    print("Term " + str(n) + " of the Fibonnaci Sequence is " + str(f[0]))
    print("It's factorial is " + str(f[1]))

if __name__ == '__main__':
    main()
