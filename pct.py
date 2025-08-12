from abc import ABC, abstractmethod

class CalculatorBase(ABC):
    @abstractmethod
    def add(self, a, b):
        pass

    @abstractmethod
    def subtract(self, a, b):
        pass

    @abstractmethod
    def multiply(self, a, b):
        pass

    @abstractmethod
    def divide(self, a, b):
        pass

class Calculator(CalculatorBase):
    def add(self, a, b):
        return self.__add(a, b)

    def subtract(self, a, b):
        return self.__subtract(a, b)

    def multiply(self, a, b):
        return self.__multiply(a, b)

    def divide(self, a, b):
        if b == 0:
            raise ValueError("Cannot divide by zero.")
        return self.__divide(a, b)

    def __add(self, a, b):
        return a + b

    def __subtract(self, a, b):
        return a - b

    def __multiply(self, a, b):
        return a * b

    def __divide(self, a, b):
        return a / b
calc = Calculator()
print(calc.add(5, 3))        
print(calc.subtract(10, 4))  
print(calc.multiply(5,4))
print(calc.divide(45,2))