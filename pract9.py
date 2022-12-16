"""
Practical 9

Use dictionary tos trore marks of the students in 4 subjects. 
Write a function to find the name of the student securing the highest percentage.

Written by Chirag Wadhwa for the University of Delhi
"""


def highestPercentage(students, maxMarks=100):
    # Calculate percentage
    for student in students:
        s = 0
        for marks in students[student]:  # Accessing values in list marks
            s += marks
        students[student][4] = (s / (4 * maxMarks)) * 100

    # print(students) 

    name = ""
    for student in students:
        if not name:
            name = student
            continue
        if students[student][4] > students[name][4]:
            name = student
    return name


def main():
    name = ""
    marks = 0
    students = dict()
    n = int(input("Enter number of Students: "))
    maxMarks = int(input("Enter maximum marks possible: "))
    for i in range(1, n + 1, 1):
        print(
            f"""
Student {i}
============"""
        )
        name = input("Enter Name: ")
        students[name] = []
        # students[name]["marks"] = []
        for j in range(1, 5, 1):
            marks = int(input(f"Enter Marks in Subject {j}: "))
            students[name].append(marks)
        students[name].append(0)    
        print()
    # print(students)
    name = highestPercentage(students, maxMarks)
    print(f"{name} secured the highest percentage.")


if __name__ == "__main__":
    main()
