#include "contact_book.h"
#include <algorithm>
#include <iostream>
using namespace std;
string specialNoneString = "None";

ContactBook::ContactBook(list<Contact> contactBook){
    this->contactBook = contactBook;
}

ContactBook::ContactBook(const ContactBook& contact_book){
    contactBook = contact_book.contactBook;
}

ContactBook::~ContactBook(){};

size_t ContactBook::get_size() const {return contactBook.size();}

void ContactBook::categoryInput(string category, string& inputString, string status){
    cout<<"Enter "<< category <<" ("<< status <<"):"<<endl;
    getline(cin, inputString);
}

Contact ContactBook::createContact(){
    Contact contact;
    string firstName, secondName, lastName, birthDate, address, email, phone_number;

    categoryInput("first name", firstName);
    while (firstName.empty()){categoryInput("first name", firstName);}
    while (!contact.isValidName(firstName)){categoryInput("first name", firstName);}
    if (!contact.set_firstName(firstName)){cout<<"Ошибка присвоения имени."<<endl;}


    categoryInput("second name", secondName);
    while (secondName.empty()){categoryInput("second name", secondName);}
    while (!contact.isValidName(secondName)){categoryInput("second name", secondName);}
    if (!contact.set_secondName(secondName)){cout<<"Ошибка присвоения фамилии."<<endl;}

    categoryInput("last name", lastName, "optional");
    while (!contact.isValidName(lastName)){categoryInput("last name", lastName, "optional");}
    if (!contact.set_lastName(lastName)){cout<<"Ошибка присвоения отчества."<<endl;}

    categoryInput("birth date", birthDate, "optional");
    while (!contact.isValidDate(birthDate)){categoryInput("birth date", birthDate, "optional");}
    if (!contact.set_birthDate(birthDate)){cout<<"Ошибка присвоения даты рождения."<<endl;}

    categoryInput("address", address, "optional");
    while (!contact.isValidAddress(address)){categoryInput("address", address, "optional");}
    if (!contact.set_address(address)){cout<<"Ошибка присвоения даты адреса."<<endl;}

    categoryInput("email", email);
    while (email.empty()){categoryInput("email", email);}
    while (!contact.isValidEmail(email)){categoryInput("email", email);}
    if (!contact.set_email(email)){cout<<"Ошибка присвоения email."<<endl;}

    categoryInput("phone number", phone_number);
    while (phone_number.empty()){categoryInput("phone number", phone_number);}
    while (!contact.isValidPhone(phone_number)){categoryInput("phone number", phone_number);}
    if (!contact.addPhoneNumber(phone_number)){cout<<"Ошибка присвоения номера телефона."<<endl;}

    categoryInput("phone number", phone_number, "keep empty to stop adding phone numbers");
    while (!phone_number.empty()){
        while (!contact.isValidPhone(phone_number)){categoryInput("phone number", phone_number);}
        if (!contact.addPhoneNumber(phone_number)){cout<<"Ошибка присвоения фамилии."<<endl;}
        categoryInput("phone number", phone_number, "keep empty to stop adding phone numbers");
    }

    return contact;
}

void ContactBook::showContacts(){
    cout<<"\nLIST OF CONTACTS\n"<<endl;
    for (Contact contact : contactBook){
        contact.show();
        cout<<"@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@"<<endl;
    }
}

bool ContactBook::addContact(const Contact& contact){
    contactBook.push_back(contact);
    return true;
}



void ContactBook::deleteContact(){
    list<Contact> list_to_delete = searchContact();
    char delete_all_status, status;

    cout<<"Want to delete all? (y/n)"<<endl;
        cin>>delete_all_status;
        cin.ignore();
    if (delete_all_status == 'y' || delete_all_status == 'Y'){
        for (Contact& contact_to_delete : list_to_delete) {
            for (auto it = contactBook.begin(); it != contactBook.end(); ) {
                if (*it == contact_to_delete) {
                    it = contactBook.erase(it);
                    break;
                } else {
                    ++it;
                }
            }
        }
    }else {
        for (Contact& contact_to_delete : list_to_delete) {
            contact_to_delete.show();
            
            char status;
            cout << "\nWant to delete this contact? (y/n)" << endl;
            cin >> status;
            cin.ignore();
            
            if (status == 'y' || status == 'Y'){
                // Находим и удаляем конкретный контакт
                for (auto it = contactBook.begin(); it != contactBook.end(); ) {
                    if (*it == contact_to_delete) {
                        it = contactBook.erase(it);
                        break;
                    } else {
                        ++it;
                    }
                }
            }
        }
    }
}

void ContactBook::updateContact(){
    list<Contact> list_to_update = searchContact();
    char opt;

    for (auto contact_to_update = contactBook.begin(); contact_to_update != contactBook.end(); contact_to_update++){
        for (Contact found_contact : list_to_update){
            if (*contact_to_update == found_contact){
                (*contact_to_update).show();
                cout<<"\nUpdate contact? (y/n)"<<endl;
                cin>>opt;
                cin.ignore();
                if (opt == 'y' || opt == 'Y'){
                    Contact temp = createContact();
                    *contact_to_update = temp;
                }
            }
        }
    }  
}

bool ContactBook::compareFirstName(const Contact& contact1, const Contact& contact2){
    return contact1.get_firstName() < contact2.get_firstName();
}

bool ContactBook::compareSecondName(const Contact& contact1, const Contact& contact2){
    return contact1.get_secondName() < contact2.get_secondName();
}

bool ContactBook::compareLastName(const Contact& contact1, const Contact& contact2){
    string lastName1 = (contact1.get_lastName().empty() ? "zzzzzzzzzz" : contact1.get_lastName());
    string lastName2 = (contact2.get_lastName().empty() ? "zzzzzzzzzz" : contact2.get_lastName());
    return lastName1 < lastName2;
}

bool ContactBook::compareBirthDate(const Contact& contact1, const Contact& contact2){
    string date1 = (contact1.get_birthDate().empty() ? "31-12-9999" : contact1.get_birthDate());
    string date2 = (contact2.get_birthDate().empty() ? "31-12-9999" : contact2.get_birthDate());
    return date1 < date2;
}

bool ContactBook::compareAddress(const Contact& contact1, const Contact& contact2){
    string address1 = (contact1.get_address().empty() ? "zzzzzzzzzz" : contact1.get_address());
    string address2 = (contact2.get_address().empty() ? "zzzzzzzzzz" : contact2.get_address());
    return address1 < address2;
}

bool ContactBook::compareEmail(const Contact& contact1, const Contact& contact2){
    return contact1.get_email() < contact2.get_email();
}

void ContactBook::showSortMenu(){
    cout<<"\nSORTING CRITERIAS\n"<<endl;
    cout << "1. Sort by First Name" << endl;
    cout << "2. Sort by Second Name" << endl;
    cout << "3. Sort by Last Name" << endl;
    cout << "4. Sort by Birth Date" << endl;
    cout << "5. Sort by Address" << endl;
    cout << "6. Sort by Email" << endl;
    cout << "7. Cancel sorting" << endl;
    cout << "Choose sorting option: ";
}

void ContactBook::sortContacts(){
    int criteria;
    
    showSortMenu();

    cin>>criteria;
    cin.ignore();

    switch (criteria)
    {
    case 1:
        contactBook.sort(compareFirstName);
        break;
    case 2:
        contactBook.sort(compareSecondName);
        break;
    case 3:
        contactBook.sort(compareLastName);
        break;
    case 4:
        contactBook.sort(compareBirthDate);
        break;
    case 5:
        contactBook.sort(compareAddress);
        break;
    case 6:
        contactBook.sort(compareEmail);
        break;
    case 7:
        break;
    default:
        cout<<"\nWrong sorting criteria!!\n"<<endl;
        return;
    }
}

void ContactBook::saveContacts(){
    if (!fileStorage.saveToFile(contactBook)){cout<<"\nError: can't open file!\n"<<endl;}
}

void ContactBook::loadContacts(){
    contactBook = fileStorage.loadFromFile(contactBook);
}

list<Contact> ContactBook::searchContact(){
    list<Contact> result;
    string find_parameters[8];
    string parametres[7] = {"first name", "second name", "last name", "birth date", "address", "email", "phone number"};
    char status;
    
    cout<<"\nDo you want find through all fields? (y/n)"<<endl;
    cin>>status;
    cin.ignore();
    if (status == 'y' || status == 'Y'){
        categoryInput("string to find", find_parameters[7], "optional");
        for (Contact& contact : contactBook){
            if ((contact).findString(find_parameters[7])){
                result.push_back(contact);
            }
        }
    } else {
        for (int i = 0; i < 7; i++){
            categoryInput(parametres[i], find_parameters[i], "optional");
        }

        for (Contact& contact : contactBook){
            bool flag = true;
            if (!find_parameters[0].empty() && !contact.findFirstName(find_parameters[0])) {flag = false;}
            if (!find_parameters[1].empty() && !contact.findSecondName(find_parameters[1])) {flag = false;}
            if (!find_parameters[2].empty() && !contact.findLastName(find_parameters[2])) {flag = false;}
            if (!find_parameters[3].empty() && !contact.findBirthDate(find_parameters[3])) {flag = false;}
            if (!find_parameters[4].empty() && !contact.findAddress(find_parameters[4])) {flag = false;}
            if (!find_parameters[5].empty() && !contact.findEmail(find_parameters[5])) {flag = false;}
            if (!find_parameters[6].empty() && !contact.findPhoneNumber(find_parameters[6])) {flag = false;}
            if (flag) {result.push_back(contact);}
        }
    }
    cout<<"Result: "<< result.size() <<" found.\n"<<endl;
    return result;
}