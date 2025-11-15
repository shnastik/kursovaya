#pragma once
#include <string>
#include <list>
using namespace std;

class Contact {
    private:
    string firstName;
    string secondName;
    string lastName;
    string birthDate;
    string address;
    string email;
    list<string> list_of_phone_numbers;

    public:
    Contact(string firstName = "", string secondName = "", string lastName = "", string birthDate = "", string address = "", string email = "", list<string> list_of_phone_numbers = {});
    Contact(const Contact &c);
    ~Contact();

    string get_firstName() const;
    string get_secondName() const;
    string get_lastName() const;
    string get_birthDate() const;
    string get_address() const;
    string get_email() const;
    list<string> get_list_of_phones() const;

    bool set_firstName(string& firstName);
    bool set_secondName(string& secondName);
    bool set_lastName(string& lastName);
    bool set_birthDate(string& birthDate);
    bool set_address(string& address);
    bool set_email(string& email);
    bool set_list_of_phones(list<string> list_of_phones);

    bool isValidName(const string& name) const;
    bool isValidEmail(const string& email) const;
    bool isValidPhone(const string& phone) const;
    bool isValidDate(const string& date) const;
    bool isValidAddress(const string& address) const;

    bool findFirstName(const string& string_to_find);
    bool findSecondName(const string& string_to_find);
    bool findLastName(const string& string_to_find);
    bool findBirthDate(const string& string_to_find);
    bool findAddress(const string& string_to_find);
    bool findEmail(const string& string_to_find);
    bool findPhoneNumber(const string& string_to_find);
    bool findString(const string& string_to_find);

    string normalizePhoneNumber(const string& PhoneNumber);
    string trim_string(const string& string) const;
    bool addPhoneNumber(const string& PhoneNumber);

    void show();

    Contact& operator=(const Contact& other);
    bool operator==(const Contact& other) const;
};

