#include "file_manager.h"
#include "contact_book.h"
#include <fstream>
using namespace std;

FileManager::FileManager(string filename){
    this->filename = filename;
}

FileManager::~FileManager(){}

list<Contact> FileManager::loadFromFile(const list<Contact>& contact_book){
    list<Contact> contacts;
    ifstream file(filename);

    if (!file.is_open()){return contacts;}
    else{
        size_t contact_count;
        file>>contact_count;
        file.ignore();

        for (size_t i = 0; i < contact_count; ++i){
            string first_name, second_name, last_name, birth_date, address, email;

            getline(file, first_name);
            getline(file, second_name);
            getline(file, last_name);
            getline(file, birth_date);
            getline(file, address);
            getline(file, email);

            size_t phone_count;
            file>>phone_count;
            file.ignore();

            list<string> phones;
            for (size_t j = 0; j < phone_count; ++j){
                string phone;
                getline(file, phone);
                phones.push_back(phone);
            }
            string separator;
            getline(file, separator);

            Contact contact(first_name, second_name, last_name, birth_date, address, email, phones);
            contacts.push_back(contact);
        }
        file.close();
    }
    return contacts;
}

bool FileManager::saveToFile(const list<Contact>& contact_book){
    ofstream file(filename);

    if (!file.is_open()){return false;}
    else{
        file<< contact_book.size() <<endl;

        for (const Contact& contact : contact_book){
            file<< contact.get_firstName() <<endl;
            file<< contact.get_secondName() <<endl;
            file<< contact.get_lastName() <<endl;
            file<< contact.get_birthDate() <<endl;
            file<< contact.get_address() <<endl;
            file<< contact.get_email() <<endl;

            list<string> phones = contact.get_list_of_phones();
            file<< phones.size() <<endl;

            for (const string& phone : phones){
                file<< phone <<endl;
            }
            file<<"+++++++++"<<endl;
        }
        file.close();
        return true;
    }
}