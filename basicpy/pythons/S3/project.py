import pickle

class InvalidInputError(Exception):
    pass

factors = {
    "car": 0.21,         # kg CO2 per km
    "bus": 0.10,         # kg CO2 per km
    "electricity": 0.85, # kg CO2 per kWh
    "meat": 2.50         # kg CO2 per serving
}

def calculate_footprint(activity, value):
    return value * factors[activity]

def save_data(name, total):
    record = {"Name": name, "Total_CO2": total}
    with open("carbon.dat", "ab") as f:
        pickle.dump(record, f)
    print("\n✅ Record saved successfully!")

def show_records():
    try:
        with open("carbon.dat", "rb") as f:
            print("\n📊 Previous Records:")
            while True:
                try:
                    record = pickle.load(f)
                    print(record)
                except EOFError:
                    break
    except FileNotFoundError:
        print("\nNo previous records found.")

def main():
    print("🌍 WELCOME TO CARBON FOOTPRINT TRACKER 🌍")
    print("-------------------------------------------")
    name = input("Enter your name: ")

    # List of activities
    activities = ["car", "bus", "electricity", "meat"]
    values = []

    for act in activities:
        try:
            value = float(input(f"Enter your {act} usage (in km/kWh/servings): "))
            if value < 0:
                raise InvalidInputError
            values.append(value)
        except ValueError:
            print("❌ Please enter a valid number!")
            return
        except InvalidInputError:
            print("❌ Value cannot be negative!")
            return

    total = 0
    for i in range(len(activities)):
        total += calculate_footprint(activities[i], values[i])

    print(f"\n{name}'s total daily carbon footprint is: {total:.2f} kg CO₂")

    # Save and show records
    save_data(name, total)
    show_records()

if __name__ == "__main__":
    main()