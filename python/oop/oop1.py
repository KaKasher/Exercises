'''
Exercise for OOP python
Topics:
- classes and instances
- class variables
- class methods and static methods
'''

class Employee:

    # class variables
    num_of_emp = 0
    raise_amount = 1.04

    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@nigga.com'

        Employee.num_of_emp += 1

    def fullname(self):
        return f'{self.first} {self.last}'

    def apply_raise(self):
        self.pay = int(self.pay * self.raise_amount)

    @classmethod
    def set_raise_amt(cls, amount):
        cls.raise_amount = amount

    @classmethod
    def from_string(cls, emp_str):
        first, last, pay = emp_str.split('-')
        return cls(first, last, pay)

    @staticmethod
    def is_workday(day):
        if day.weekday() == 5 or day.weekday == 6:
            return False
        return True

emp_1 = Employee('Kacper', 'Koksu', '1000')
emp_2 = Employee('Potezny', 'G', '90000')

emp_1.fullname() # what we use
Employee.fullname(emp_1) # what happens in the background

emp_str_1 = 'kaka-greg-5000'
emp_str_2 = 'bob-marley-6000'

new_emp_1 = Employee.from_string(emp_str_1)
new_emp_2 = Employee.from_string(emp_str_2)

import datetime
my_date = datetime.date(2019, 12, 5)

print(Employee.is_workday(my_date))


