
# print('start code')
# x=int(input("no 1:"))
# y=int(input("no 2:"))

# try:
#     z=int(x)/int(y)
#     print(z)
# except ZeroDivisionError as msg:
#     print(msg)
#     print('Division by 0 is not possible')

# except ValueError as msg:
#     print(msg)
#     print('input data is not int type')

# print('rest of code')

#write a program to enter exeption index error and attribute error

print('start code')

str='Aditya'
str2='aps'
try:
    print(str[7])
except IndexError as msg:
    print(msg)
else:
    print(str)
try:
    str.append(str2)
    print(str)
except AttributeError as msg:
    print(msg)



