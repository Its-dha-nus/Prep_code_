import pickle
import os
def add_record():
    with open('book.dat', 'ab') as f:
        book_no = int(input("Enter Book Number: "))
        book_name = input("Enter Book Name: ")
        author = input("Enter Author Name: ")
        price = float(input("Enter Price: "))
        book_data = [book_no, book_name, author, price]
        pickle.dump(book_data, f)
        print("\n✅ Record successfully added!")
def display_records():
    print("\n--- All Book Records ---")
    try:
        with open('book.dat', 'rb') as f:
            record_count = 0
            while True:
                try:
                    book = pickle.load(f)
                    print(f"  Book No: {book[0]}")
                    print(f"  Name:    {book[1]}")
                    print(f"  Author:  {book[2]}")
                    print(f"  Price:   ${book[3]:.2f}")
                    print("-" * 20)
                    record_count += 1
                except EOFError:
                    if record_count == 0:
                        print("No records found in the file.")
                    break
    except FileNotFoundError:
        print("File 'book.dat' not found. No records to display.")
def books_by_author():
    author_name = input("Enter the Author's name to search for: ").strip()
    found = False
    print(f"\n--- Books by {author_name} ---")
    try:
        with open('book.dat', 'rb') as f:
            while True:
                try:
                    book = pickle.load(f)
                    if book[2].lower() == author_name.lower():
                        print(f"  Book No: {book[0]}, Name: {book[1]}, Price: ${book[3]:.2f}")
                        found = True
                except EOFError:
                    break
        if not found:
            print(f"No books found written by {author_name}.")
    except FileNotFoundError:
        print("File 'book.dat' not found. No records to search.")
def books_by_price(max_price):
    found = False
    print(f"\n--- Books Costing Less Than ${max_price:.2f} ---")
    try:
        with open('book.dat', 'rb') as f:
            while True:
                try:
                    book = pickle.load(f)
                    if book[3] < max_price:
                        print(f"  Book No: {book[0]}, Name: {book[1]}, Author: {book[2]}, Price: ${book[3]:.2f}")
                        found = True
                except EOFError:
                    break
        if not found:
            print(f"No books found with a price less than ${max_price:.2f}.")
    except FileNotFoundError:
        print("File 'book.dat' not found. No records to search.")
def copy_data():
    count = 0
    try:
        with open('book.dat', 'rb') as f_in, open('costly_book.dat', 'wb') as f_out:
            while True:
                try:
                    book = pickle.load(f_in)
                    if book[3] > 500:
                        pickle.dump(book, f_out)
                        count += 1
                except EOFError:
                    break
        return count
    except FileNotFoundError:
        print("File 'book.dat' not found. Cannot copy data.")
        return 0
def delete_record(book_number):
    found = False
    try:
        with open('book.dat', 'rb') as f_in, open('temp.dat', 'wb') as f_out:
            while True:
                try:
                    book = pickle.load(f_in)
                    if book[0] == book_number:
                        found = True 
                    else:
                        pickle.dump(book, f_out) 
                except EOFError:
                    break
        os.remove('book.dat')
        os.rename('temp.dat', 'book.dat')
        if found:
            print(f"\n✅ Record for Book No: {book_number} has been deleted.")
        else:
            print(f"\n❌ Record for Book No: {book_number} was not found.") 
    except FileNotFoundError:
        print("File 'book.dat' not found. Cannot delete.")
def update_record(book_number):
    found = False
    try:
        with open('book.dat', 'rb') as f_in, open('temp.dat', 'wb') as f_out:
            while True:
                try:
                    book = pickle.load(f_in)
                    if book[0] == book_number:
                        found = True
                        print("\nRecord found. Enter new details:")
                        new_name = input(f"Enter new name (current: {book[1]}): ")
                        new_author = input(f"Enter new author (current: {book[2]}): ")
                        new_price = float(input(f"Enter new price (current: {book[3]}): "))
                        updated_book = [book_number, new_name, new_author, new_price]
                        pickle.dump(updated_book, f_out)
                    else:
                        pickle.dump(book, f_out)
                except EOFError:
                    break
        os.remove('book.dat')
        os.rename('temp.dat', 'book.dat') 
        if found:
            print(f"\n✅ Record for Book No: {book_number} has been updated.")
        else:
            print(f"\n❌ Record for Book No: {book_number} was not found.")     
    except FileNotFoundError:
        print("File 'book.dat' not found. Cannot update.")
def main():
    """
    Main function to display the menu and run the program.
    """
    while True:
        print("\n--- 📚 Book Management System ---")
        print("1. Add a New Book Record")
        print("2. Display All Book Records")
        print("3. Search Books by Author")
        print("4. Search Books by Price")
        print("5. Copy Costly Books (Price > 500)")
        print("6. Delete a Book Record")
        print("7. Update a Book Record")
        print("8. Exit") 
        choice = input("Enter your choice (1-8): ")
        if choice == '1':
            add_record()
        elif choice == '2':
            display_records()
        elif choice == '3':
            books_by_author()      
        elif choice == '4':
            price_limit = float(input("Enter the maximum price to search for: "))
            books_by_price(price_limit)
        elif choice == '5':
            count = copy_data()
            if count > 0:
                print(f"\n✅ Successfully copied {count} record(s) to 'costly_book.dat'.")
            else:
                print("\nNo records were copied.")            
        elif choice == '6':
            b_no = int(input("Enter Book Number to delete: "))
            delete_record(b_no)   
        elif choice == '7':
            b_no = int(input("Enter Book Number to update: "))
            update_record(b_no)
        elif choice == '8':
            print("\nThank you for using the Book Management System. Goodbye!")
            break
        else:
            print("\n❌ Invalid choice. Please enter a number between 1 and 8.")
if __name__ == "__main__":
    main()