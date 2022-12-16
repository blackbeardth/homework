'''
Practical 2

Consider a showroom of electronic products, where there are various
salesmen. Each salesman is given a commission of 5%, depending on the sales
made per month. In case the sale done is less than 50000, then the salesman is
not given any commission. Write a function to calculate total sales of a salesman
in a month, commission and remarks for the salesman. Sales done by each
salesman per week is to be provided as input. Use tuples / list to store data of
salesmen.
Assign remarks according to the following criteria:
Excellent: Sales >=80000
Good: Sales>=60000 and < 80000
Average: Sales>=40000 and < 60000
Work Hard: Sales < 40000

Written by Chirag Wadhwa for the University of Delhi
'''
import os


def sales():

    salesmen = []  # empty list to store data of all salesmen
    sales = 0
    n = int(input("Enter number of salesmen: "))
    assert n >= 0, "Invalid input"

    for i in range(n):
        salesman = [0, 0, ""]  # list to store data of salesman

        # salesman[0] = sales
        # salesman[1] = commision
        # salesman[2] = remaks

        # Sales
        for j in range(4):
            sales = float(
                input("Enter sales for employee %d in week %d : " % (i + 1, j + 1))
            )
            assert sales >= 0, "invalid entry"
            salesman[0] += sales

        # Commision
        if salesman[0] > 50000:
            salesman[1] = salesman[0] * 0.05

        # Remark
        if salesman[0] >= 80000:
            salesman[2] = "Excellent"
        elif 80000 > salesman[0] >= 60000:
            salesman[2] = "Good"
        elif 60000 > salesman[0] >= 40000:
            salesman[2] = "Average"
        elif 40000 > salesman[0]:
            salesman[2] = "Work Hard"

        salesmen.append(salesman)  # appending data of salesman to list

    return salesmen, n # tuple


def main():
    data, n = sales()
    os.system("CLS")
    print("\n%45s" % ("PERFORMANCE REPORT"))
    print("%46s" % ("--------------------"))
    print(
        "%-20s %-20s %-20s %-20s"
        % ("Salesman No.", "Total Sales", "Commision", "Remark")
    )
    print("------------------------------------------------------------------------")
    for i in range(0, n):
        print(
            "%-20d %-20.2f %-20.2f %-20s" % (i + 1, data[i][0], data[i][1], data[i][2])
        )


# Driver
main()
