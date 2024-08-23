#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <limits>

class ExpenseTracker {
public:
    ExpenseTracker() {
        categories = {"Food", "Transportation", "Entertainment", "Utilities", "Others"};
        for (const std::string &category : categories) {
            expenses[category] = std::vector<double>();
        }
    }

    void addExpense(int categoryIndex, double amount) {
        if (categoryIndex >= 1 && categoryIndex <= categories.size()) {
            const std::string &category = categories[categoryIndex - 1];
            expenses[category].push_back(amount);
            std::cout << "Added Rs" << std::fixed << std::setprecision(2) << amount << " to " << category << " expenses.\n";
        } else {
            std::cerr << "Error: Invalid category! Please choose from the predefined categories.\n";
        }
    }

    void viewExpenses() const {
        double totalExpenses = 0;
        std::cout << "--- Total Expenses ---\n";
        for (const auto &pair : expenses) {
            double categoryTotal = sum(pair.second);
            totalExpenses += categoryTotal;
            std::cout << pair.first << ": Rs" << std::fixed << std::setprecision(2) << categoryTotal << "\n";
        }
        std::cout << "Overall total expenses: Rs" << std::fixed << std::setprecision(2) << totalExpenses << "\n";
    }

    double categoryExpenses(int categoryIndex) const {
        if (categoryIndex >= 1 && categoryIndex <= categories.size()) {
            const std::string &category = categories[categoryIndex - 1];
            return sum(expenses.at(category));
        } else {
            std::cerr << "Error: Invalid category!\n";
            return 0;
        }
    }

    void menu() {
        int choice;
        do {
            std::cout << "\nExpense Tracker Menu:\n";
            std::cout << "1. Add Expense\n";
            std::cout << "2. View Total Expenses\n";
            std::cout << "3. View Category Expenses\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addExpenseCallback();
                    break;
                case 2:
                    viewExpenses();
                    break;
                case 3:
                    viewCategoryExpensesCallback();
                    break;
                case 4:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cerr << "Invalid choice! Please try again.\n";
            }
        } while (choice != 4);
    }

private:
    std::vector<std::string> categories;
    std::map<std::string, std::vector<double>> expenses;

    void addExpenseCallback() {
        int categoryIndex;
        double amount;
        std::cout << "Choose Category:\n";
        for (size_t i = 0; i < categories.size(); ++i) {
            std::cout << (i + 1) << ". " << categories[i] << "\n";
        }
        std::cout << "Enter the number corresponding to the category: ";
        std::cin >> categoryIndex;

        std::cout << "Enter Amount: ";
        std::cin >> amount;

        if (std::cin.fail()) {
            std::cerr << "Error: Invalid amount! Please enter a valid number.\n";
            std::cin.clear();  // Clear the error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore remaining input
            return;
        }

        addExpense(categoryIndex, amount);
    }

    void viewCategoryExpensesCallback() {
        int categoryIndex;
        std::cout << "Choose Category:\n";
        for (size_t i = 0; i < categories.size(); ++i) {
            std::cout << (i + 1) << ". " << categories[i] << "\n";
        }
        std::cout << "Enter the number corresponding to the category: ";
        std::cin >> categoryIndex;
        double categoryTotal = categoryExpenses(categoryIndex);
        if (categoryIndex >= 1 && categoryIndex <= categories.size()) {
            std::cout << "Total " << categories[categoryIndex - 1] << " expenses: Rs" << std::fixed << std::setprecision(2) << categoryTotal << "\n";
        }
    }

    double sum(const std::vector<double> &amounts) const {
        double total = 0;
        for (double amount : amounts) {
            total += amount;
        }
        return total;
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.menu();
    return 0;
}
