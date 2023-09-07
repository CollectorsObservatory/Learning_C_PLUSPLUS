# Define a Calculator class to encapsulate calculations
# Basically this exists to stay fresh in python and to warm up
class Calculator:
    def __init__(self, num_1, num_2, operation, ans=0):
        self.num_1 = num_1
        self.num_2 = num_2
        self.ans = ans
        self.operation = operation

    def addition(self):
        return f"Result is {self.num_1 + self.num_2}"

    def subs(self):
        return f"Result is {self.num_1 - self.num_2}"


# Create an empty dictionary to store calculation results
ans_dic = {}

# Define a list of valid operators
operator_list = ["-", "+"]

# Print a welcome message
print("Welcome to Basic calculator")

# Define the output format
output_format = "FORMAT: NUMBER1, NUMBER2, OPERATION, RESULT"

# Start an infinite loop to keep the calculator running
while True:
    try:
        # Get the user's input for the first number
        number_1 = float(input("Please enter the first number: "))
        # Get the user's input for the second number
        number_2 = float(input("Please enter the second number: "))
        # Get the user's choice of operation
        operator = str(input("Choose the operation (+ or -): "))
        print(" ")

        # Check if the operator is valid, if not, prompt the user to try again
        if operator not in operator_list:
            print("Please try again")

        # Create a Calculator instance with user inputs
        calculation = Calculator(num_1=number_1, num_2=number_2, operation=operator)

        # Perform addition if the operator is '+'
        if operator == "+":
            print(calculation.addition())
            ans_dic.update({operator: calculation.addition()})
            print(output_format)
            print(f"{number_1}, {number_2}, {ans_dic}")

        # Perform subtraction if the operator is '-'
        elif operator == "-":
            print(calculation.subs())
            ans_dic.update({operator: calculation.subs()})
            print(output_format)
            print(f"{number_1}, {number_2}, {ans_dic}")

        print(" ")
        # Ask the user if they want to continue or exit
        print("Press enter to continue or type 'exit' to exit")
        choice = input("")
        if choice.lower() == "exit":
            print("Closing the program")
            break  # Exit the loop if the user wants to exit
        else:
            continue  # Continue to the next iteration of the loop

    except ValueError:
        print("Please try again")  # Handle invalid inputs

# End of the program
class User:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def user_info(self):
        return f"{self.name} is {self.age} years old"


name_input = str(input("Please enter your name: "))
if name_input.lower() == "fares":
    print("this a functional copy for my C++ program")
    age_input = int(input("Please enter your age: "))
    try:
        if 0<age_input <=20:
            new_user = User(name=name_input, age=age_input)
            print(new_user.user_info())
    except ValueError:
        print("Try again")
else:
    print("Try again")
