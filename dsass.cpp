#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Node structure for linked list
struct Contact {
    string name;
    string phone;
    string email;
    string address;
    Contact* next;
};

// Class for Phone Book Management System
class PhoneBook {
private:
    Contact* head;

public:
    PhoneBook() : head(nullptr) {}

    // Function to add a contact
    void addContact() {
        Contact* newContact = new Contact();
        cout << "Enter Name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, newContact->name);
        cout << "Enter Phone: ";
        getline(cin, newContact->phone);
        cout << "Enter Email: ";
        getline(cin, newContact->email);
        cout << "Enter Address: ";
        getline(cin, newContact->address);
        newContact->next = nullptr;

        // Insert in sorted order
        if (head == nullptr || head->name > newContact->name) {
            newContact->next = head;
            head = newContact;
        } else {
            Contact* current = head;
            while (current->next != nullptr && current->next->name < newContact->name) {
                current = current->next;
            }
            newContact->next = current->next;
            current->next = newContact;
        }
        cout << "Contact added successfully!" << endl;
    }

    // Function to delete a contact
    void deleteContact() {
        string name;
        cout << "Enter name to delete: ";
        cin.ignore();
        getline(cin, name);

        Contact* current = head;
        Contact* previous = nullptr;

        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Contact not found!" << endl;
            return;
        }

        if (previous == nullptr) {
            head = current->next; // Deleting head
        } else {
            previous->next = current->next; // Bypass the current node
        }
        delete current;
        cout << "Contact deleted successfully!" << endl;
    }

    // Function to search for a contact
    void searchContact() {
        string name;
        cout << "Enter name to search: ";
        cin.ignore();
        getline(cin, name);

        Contact* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Contact Found!" << endl;
                cout << "Name: " << current->name << endl;
                cout << "Phone: " << current->phone << endl;
                cout << "Email: " << current->email << endl;
                cout << "Address: " << current->address << endl;
                return;
            }
            current = current->next;
        }
        cout << "Contact not found!" << endl;
    }

    // Function to update a contact
    void updateContact() {
        string name;
        cout << "Enter name to update: ";
        cin.ignore();
        getline(cin, name);

        Contact* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Enter new phone: ";
                getline(cin, current->phone);
                cout << "Enter new email: ";
                getline(cin, current->email);
                cout << "Enter new address: ";
                getline(cin, current->address);
                cout << "Contact updated successfully!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Contact not found!" << endl;
    }

    // Function to display all contacts
    void displayContacts() {
        if (head == nullptr) {
            cout << "No contacts available. Please add some." << endl;
            return;
        }
        cout << "=== Contact List ===" << endl;
        Contact* current = head;
        int index = 1;
        while (current != nullptr) {
            cout << index++ << ". Name: " << current->name << endl;
            cout << "   Phone: " << current->phone << endl;
            cout << "   Email: " << current->email << endl;
            cout << "   Address: " << current->address << endl;
            current = current->next;
        }
    }

    // Function to save contacts to a file
    void saveContactsToFile() {
        ofstream outFile("contacts.txt");
        if (!outFile) {
            cout << "Error opening file for writing!" << endl;
            return;
        }
        Contact* current = head;
        while (current != nullptr) {
            outFile <<"Name: "+ current->name << endl;
            outFile <<"Phone: "+ current->phone << endl;
            outFile <<"Email: "+ current->email << endl;
            outFile <<"Address: "+ current->address+"\n" << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Contacts saved successfully!" << endl;
    }

    // Function to load contacts from a file
    void loadContactsFromFile() {
        ifstream inFile("contacts.txt");
        if (!inFile) {
            cout << "No contacts to load." << endl;
            return;
        }
        while (!inFile.eof()) {
            Contact* newContact = new Contact();
            getline(inFile, newContact->name);
            if (newContact->name.empty()) break; // Check for empty line
            getline(inFile, newContact->phone);
            getline(inFile, newContact->email);
            getline(inFile, newContact->address);
            newContact->next = nullptr;

            // Insert in sorted order
            if (head == nullptr || head->name > newContact->name) {
                newContact->next = head;
                head = newContact;
            } else {
                Contact* current = head;
                while (current->next != nullptr && current->next->name < newContact->name) {
                    current = current->next;
                }
                newContact->next = current->next;
                current->next = newContact;
            }
        }
        inFile.close();
        cout << "Contacts loaded successfully!" << endl;
    }

    // Destructor to free memory
    ~PhoneBook() {
        Contact* current = head;
        while (current != nullptr) {
            Contact* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Main function
int main() {
    PhoneBook phoneBook;
    phoneBook.loadContactsFromFile();

    int choice;
    do {
        cout << "=== PHONE BOOK MANAGEMENT ===" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Update Contact" << endl;
        cout << "5. Display All Contacts" << endl;
        cout << "6. Save & Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: phoneBook.addContact(); break;
            case 2: phoneBook.deleteContact(); break;
            case 3: phoneBook.searchContact(); break;
            case 4: phoneBook.updateContact(); break;
            case 5: phoneBook.displayContacts(); break;
            case 6: phoneBook.saveContactsToFile(); break;
            default: cout << "Invalid choice! Please try again." << endl; break;
        }
    } while (choice != 6);

    return 0;
}
