"""
Practical 4

Write a function that takes a number (n >= 10) as an
input and return the digits of the numbers as a set.

Written by Chirag Wadhwa for the University of Delhi
"""


def setOfDigits(n):
    assert n >= 10, "invalid input"
    s = set()
    while n != 0:
        s.add(n % 10)
        n //= 10
    return s


def main():
    n = int(input("Enter a number: "))
    print("Set of digits: " +  str(setOfDigits(n)))


if __name__ == '__main__':
	main()  
# This means that the indented code will
# be executed only when source code in executed directly
