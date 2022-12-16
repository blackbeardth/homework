"""
Practical 1

Write a function that takes the lengths of three sides: side1, side2 and side3 of
the triangle as the input from the user using input function and return the area
and perimeter of the triangle as a tuple. Also, assert that sum of the length of any
two sides is greater than the third side.

Written by Chirag Wadhwa for the University of Delhi
"""


def traingle():
    side1 = float(input("Enter length of side 1: "))
    side2 = float(input("Enter length of side 2: "))
    side3 = float(input("Enter length of side 3: "))

    assert side1 < side2 + side3, "Such a triangle doesn't exist!"
    assert side2 < side1 + side3, "Such a triangle doesn't exist!"
    assert side3 < side2 + side1, "Such a triangle doesn't exist!"

    per = side1 + side2 + side3
    s = per / 2
    area = (s * (s - side1) * (s - side2) * (s - side3)) ** 0.5

    return per, area


# Driver
perimeter, area = traingle()
print("Perimeter =", perimeter, "cm\nArea =", area, "cm.sq")
