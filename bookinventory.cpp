#include <iostream>
#include <string>
using namespace std;
void ShowDetails(); //add function proto

class Book {
private:
    string title;
    string author;
    double price;
    int stockPosition;

public:

    Book(string title, string author, double price, int stockPosition)
        : title(title), author(author), price(price), stockPosition(stockPosition) {}

    
    void ShowDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: R" << price << endl;
        cout << "Stock Position: " << stockPosition << " copies" << endl;
    }

    // Function to process order
    void Order(int RequestNum) {
        if (RequestNum <= stockPosition) {
            cout << "Book is available!" << endl;
            ShowDetails();
            cout << "How many copies do you want?: ";
            int copyNum;
            cin >> copyNum;

            if (copyNum <= stockPosition) {
                double totalCost = copyNum * price;
                cout << "Total cost for " << copyNum << " copies: R" << totalCost << endl;
            } else {
                cout << "Required copies not in ." << endl;
            }
        } else {
            cout << "We don't have the quantity you want." << endl;
        }
    }

    // Getter methods
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
};

int main() {
    // Create sample books
    Book book1("Whats For Dinner", "A Blah", 400.0, 1);
    Book book2("Coding is Argh", "Kick Doo", 10.0, 155);
    Book book3("Richfield Wars", "Hellish B", 12000.0, 1);
    Book book4("Try Graduating", "Madonna Richfield", 1.0, 200);
    Book book5("Why did i even try", "Haha Lol", 5.0, 2);

    // Input from user
    string title, author;
    cout << "Title of the book requested: ";
    getline(cin, title);

    cout << "Author of the book: ";
    getline(cin, author);

    if (title == book1.getTitle() && author == book1.getAuthor()) {
        book1.Order(1); 
    } else if (title == book2.getTitle() && author == book2.getAuthor()) {
        book2.Order(1); 
    } else if (title == book3.getTitle() && author == book3.getAuthor()) {
        book3.Order(1); 
    } else if (title == book4.getTitle() && author == book4.getAuthor()) {
        book4.Order(1); 
    } else if (title == book5.getTitle() && author == book5.getAuthor()) {
        book5.Order(1); 
    } else {
        cout << "Book not found sorry!" << endl;
    }

    return 0;
}
