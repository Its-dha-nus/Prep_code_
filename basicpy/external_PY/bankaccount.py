class BankAccount:
  def __init__(self,acc_num,name,balance=0):
    self.acc_num=acc_num
    self.name=name
    self.balance=balance
  def deposit(self,amount):
    if amount>0:
      self.balance +=amount
      print("Deposited.")
    else:
      print("cant do with negative number.")
  def withdraw(self,amount):
    if amount>0:
      if amount<self.balance:
        self.balance -= amount
      else:
        print("Insufficinent")
    else:
      print("cant do with -ve")
  def display(self):
    print("Account details!!")
    print("holder",self.name,"(",self.accountnumber,")")
    print("Balance:",self.balance)
def main():
  accounts={}
  while True:
    print("1-create account,2-deposit,3-withdraw,4-display,5-exit")
    choice=input("enter the number:")
    if choice=='1':
      accnum=input("Enter the acocunt number")
      if accnum in accounts:
        print("Already exists")
        continue
      name=input("Enter the name:")
      balance=float(input("enter the number:"))
      if balance<0:
        print("Balance should be +ve")
        continue
      accounts[accnum]=BankAccount(accnum,name,balance)
      print("Success!")
    elif choice in ('2','3','4'):
      accnum=input("enter the account number:")
      account=accounts.get(accnum)
      if not account:
        print("no account found!")
        continue
      if choice=='2':
        amount=float(input("Enter the amount to deposit:"))
        account.deposit(amount)
      elif choice=='3':
        amount=float(input("Enter the amount:"))
        account.withdraw(amount)
      elif choice=='4':
        account.display()
    elif choice=='5':
      print("thank u !!")
      break
main()
