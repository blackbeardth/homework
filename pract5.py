"""
Practical 5
Write a function that finds of the sum of n terms of the series. 
Import the factorial function created in Q3.

1 - x^2 / 2! + x^4 / 4! - x^6 / 6! + . . . + x^n / n! 

Written by Chirag Wadhwa for the University of Delhi
"""

from pract3 import factorial


def seriesSum(x, n):
    assert n > 0, "invalid number"
    e = 2
    s = 1
    sign = 1
    for i in range(n - 1):
        sign *= -1
        s += sign * (x**e) / factorial(e)
        e += 2
    return s


def main():
    x = float(input("Enter x: "))
    n = int(input("Enter n: "))
    print(f"Sum of {n} terms of the Series: ", seriesSum(x, n))


if __name__ == "__main__":
    main()
