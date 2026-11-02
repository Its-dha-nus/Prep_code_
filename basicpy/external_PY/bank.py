class BankAccount:
    def __init__(self, account_number, holder_name, initial_balance=0.0):
        self.account_number = account_number
        self.holder_name = holder_name
        self.balance = initial_balance
    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposit successful. New balance: ${self.balance:.2f}")
        else:
            print("Invalid deposit amount. Please deposit a positive value.")
    def withdraw(self, amount):
        if amount <= 0:
            print("Invalid withdrawal amount. Please enter a positive value.")
        elif amount > self.balance:
            print(f"Withdrawal failed. Insufficient funds. You only have ${self.balance:.2f}.")
        else:
            self.balance -= amount
            print(f"Withdrawal successful. Remaining balance: ${self.balance:.2f}")
    def display(self):
        print("\n--- Account Details ---")
        print(f"Account Holder: {self.holder_name}")
        print(f"Account Number: {self.account_number}")
        print(f"Current Balance: ${self.balance:.2f}")
        print("-----------------------")
def get_float_input(prompt):
    while True:
        try:
            value_str = input(prompt)
            value = float(value_str)
            return value
        except ValueError:
            print("Invalid input. Please enter a number.")
def account_menu(account):
    while True:
        print(f"\n--- Account Menu for {account.holder_name} ({account.account_number}) ---")
        print("1. Deposit")
        print("2. Withdraw")
        print("3. Display Account Details")
        print("4. Return to Main Menu")
        choice = input("Enter your choice (1-4): ")
        if choice == '1':
            amount = get_float_input("Enter amount to deposit: ")
            account.deposit(amount)
        elif choice == '2':
            amount = get_float_input("Enter amount to withdraw: ")
            account.withdraw(amount)
        elif choice == '3':
            account.display()
        elif choice == '4':
            print("Returning to main menu...")
            break
        else:
            print("Invalid choice. Please select from 1 to 4.")
def main():
    accounts = {} # Dictionary to store accounts, keyed by account number
    print("--- Welcome to Simple Bank ---")
    while True:
        print("\n--- Main Menu ---")
        print("1. Create New Account")
        print("2. Access Existing Account")
        print("3. List All Accounts")
        print("4. Exit")
        choice = input("Enter your choice (1-4): ")
        if choice == '1':
            print("\n--- Create New Account ---")
            acc_num = input("Enter new account number: ")
            if acc_num in accounts:
                print("Error: An account with this number already exists.")
            else:
                name = input("Enter account holder's name: ")
                balance = get_float_input("Enter initial balance (default 0): ")
                new_account = BankAccount(acc_num, name, balance)
                accounts[acc_num] = new_account
                print(f"Account for {name} created successfully!")
        elif choice == '2':
            print("\n--- Access Account ---")
            acc_num = input("Enter account number: ")
            account = accounts.get(acc_num)
            if account:
                account_menu(account)
            else:
                print("Error: Account not found.")
        elif choice == '3':
            print("\n--- All Accounts ---")
            if not accounts:
                print("No accounts have been created yet.")
            else:
                for acc_num, account in accounts.items():
                    print(f"Acc: {acc_num}, Holder: {account.holder_name}, Balance: ${account.balance:.2f}")
        elif choice == '4':
            print("Thank you for using Simple Bank. Goodbye!")
            break
        else:
            print("Invalid choice. Please select from 1 to 4.")
if __name__ == "__main__":
    main()