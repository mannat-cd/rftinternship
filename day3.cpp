#include <iostream>
#include <string>

class Item {
protected:
    int id;
    std::string title;
    bool isIssued;

public:
    Item(int id, std::string title) : id(id), title(title), isIssued(false) {}

    virtual void displayDetails() {
        std::cout << "ID: " << id << " | Title: " << title 
                  << " | Status: " << (isIssued ? "Checked Out" : "Available") << std::endl;
    }

    void issueItem() {
        if (!isIssued) {
            isIssued = true;
            std::cout << title << " has been issued." << std::endl;
        } else {
            std::cout << title << " is already out." << std::endl;
        }
    }

    void returnItem() {
        isIssued = false;
        std::cout << title << " has been returned." << std::endl;
    }

    bool getStatus() const { return isIssued; }
};
class Book : public Item {
private:
    std::string author;

public:
    Book(int id, std::string title, std::string author) 
        : Item(id, title), author(author) {}

    void displayDetails() override {
        std::cout << "[BOOK] ";
        Item::displayDetails(); // Call base class display
        std::cout << "       Author: " << author << std::endl;
    }
};

class Magazine : public Item {
private:
    int issueNumber;

public:
    Magazine(int id, std::string title, int issueNumber) 
        : Item(id, title), issueNumber(issueNumber) {}

    void displayDetails() override {
        std::cout << "[MAGAZINE] ";
        Item::displayDetails();
        std::cout << "           Issue #: " << issueNumber << std::endl;
    }
};
int main() {
    Book b1(101, "The Great Gatsby", "F. Scott Fitzgerald");
    Magazine m1(201, "National Geographic", 542);

    // Testing Functions
    b1.displayDetails();
    b1.issueItem();
    
    m1.displayDetails();

    // Bonus: Simple Fine Calculation
    int daysOverdue = 5;
    double finePerDay = 0.50;
    if (daysOverdue > 0) {
        std::cout << "\nFine for " << b1.getStatus() << " (5 days): $" 
                  << (daysOverdue * finePerDay) << std::endl;
    }

    return 0;
}