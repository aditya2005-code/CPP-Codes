class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def pay_bill(self, other):
        if self.age > other.age:
            print(f"{self.name} pays the bill because he is older than {other.name}.")
        elif self.age < other.age:
            print(f"{other.name} pays the bill because he is older than {self.name}.")
        else:
            print(f"Both are of the same age. They split the bill.")


p1 = Person("Aditya",20)
p2 = Person("Gagan",21)

p1.pay_bill(p2)

