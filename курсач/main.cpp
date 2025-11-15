#include <iostream>
#include "contact_book.h"
#include "contact.h"
#include "file_manager.h"
#include "contact_book.cpp"
#include "contact.cpp"
#include "file_manager.cpp"
using namespace std;

void showMenu();
void run_app(ContactBook& contact_book);

int main(){
    ContactBook contact_book;

    run_app(contact_book);
    
    return 0;
}

void showMenu(){
    cout<<"\nMENU\n"<<endl;
    cout<<"1. Show all contacts."<<endl;
    cout<<"2. Add contact."<<endl;
    cout<<"3. Update contacts."<<endl;
    cout<<"4. Delete contacts."<<endl;
    cout<<"5. Sort contacts."<<endl;
    cout<<"6. End"<<endl;
    cout<<"\nOption: ";
}

void run_app(ContactBook& contact_book){
    int option;

    showMenu();
    cin>>option;
    cin.ignore();

    while (option > 0 && option < 7){
        switch (option){
            case 1:
                contact_book.loadContacts();
                contact_book.showContacts();
                break;
            case 2:
                contact_book.loadContacts();
                contact_book.addContact(contact_book.createContact());
                contact_book.saveContacts();
                break;
            case 3:
                contact_book.loadContacts();
                contact_book.deleteContact();
                contact_book.saveContacts();
                break;
            case 4:
                contact_book.loadContacts();
                contact_book.updateContact();
                contact_book.saveContacts();
                break;
            case 5:
                contact_book.loadContacts();
                contact_book.sortContacts();
                contact_book.saveContacts();
                break;
            case 6:
                contact_book.saveContacts();
                return;
        }
        showMenu();
        cin>>option;
        cin.ignore();
    }
}

