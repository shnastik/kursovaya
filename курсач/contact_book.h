#pragma once
#include "Contact.h"
#include "file_manager.h"
#include <vector>
#include <string>
using namespace std;

enum SearchCriteria{FIRST_NAME = 1, SECOND_NAME, LAST_NAME, BIRTH_DATE, ADDRESS, EMAIL, PHONE_NUMBER, ALL};

class ContactBook {
    private:
    list<Contact> contactBook;
    FileManager fileStorage;
    public:
    ContactBook(list<Contact> contactBook = {});
    ContactBook(const ContactBook& contact_book);
    ~ContactBook();

    size_t get_size() const;

    
    Contact createContact();
    void showContacts();
    bool addContact(const Contact& contact);
    list<Contact> searchContact();
    void deleteContact();
    void updateContact();

    void showSortMenu();
    void sortContacts();

    static bool compareFirstName(const Contact& contact1, const Contact& contact2);
    static bool compareSecondName(const Contact& contact1, const Contact& contact2);
    static bool compareLastName(const Contact& contact1, const Contact& contact2);
    static bool compareBirthDate(const Contact& contact1, const Contact& contact2);
    static bool compareAddress(const Contact& contact1, const Contact& contact2);
    static bool compareEmail(const Contact& contact1, const Contact& contact2);
    static bool compareFirstNameDecr(const Contact& contact1, const Contact& contact2);
    static bool compareSecondNameDecr(const Contact& contact1, const Contact& contact2);
    static bool compareLastNameDecr(const Contact& contact1, const Contact& contact2);
    static bool compareBirthDateDecr(const Contact& contact1, const Contact& contact2);
    static bool compareAddressDecr(const Contact& contact1, const Contact& contact2);
    static bool compareEmailDecr(const Contact& contact1, const Contact& contact2);

    void saveContacts();
    void loadContacts();

    void categoryInput(string category, string& inputString, string status = "compulsory");
};
