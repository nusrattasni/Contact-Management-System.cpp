#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct Contact{
string name;
    string phone;
    string email;
};
vector<Contact> contacts;
void addContact(){
Contact c;
    cout << "\nEnter Name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter Phone: ";
    getline(cin, c.phone);
    cout << "Enter Email: ";
    getline(cin, c.email);
    contacts.push_back(c);
    cout << "✅ Contact added successfully!\n";
}
void viewContacts()
{
     if (contacts.empty()) {
        cout << "\nNo contacts found.\n";
        return;
}
 cout << "\n--- Contact List ---\n";
 for (const auto& c : contacts){
    cout << "Name: " << c.name
             << " | Phone: " << c.phone
             << " | Email: " << c.email << endl;
    }
 }
 void searchContact(){
 if (contacts.empty()) {
        cout << "\nNo contacts to search.\n";
        return;
 }
 string key;
 cout << "\nEnter name to search: ";
    cin.ignore();
    getline(cin, key);
    bool found = false;
      for (const auto& c : contacts){
         if (c.name == key){
            cout << "Found -> Name: " << c.name
                 << ", Phone: " << c.phone
                 << ", Email: " << c.email << endl;
            found = true;
            break;
         }
      }
    if (!found)
        cout << "❌ Contact not found.\n";
}
void sortContacts() {
    sort(contacts.begin(), contacts.end(),
         [](Contact a, Contact b) {
             return a.name < b.name;
         });
    cout << "✅ Contacts sorted by name.\n";
}
int main(){
int choice;
    do{cout << "\n Contact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Sort Contacts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
          case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: sortContacts(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
            }
        }
        while (choice != 5);
    return 0;
}




