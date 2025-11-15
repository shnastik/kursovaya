#pragma once
#include "contact.h"
#include <vector>
#include <string>
using namespace std;

class FileManager {
private:
    string filename;
public:
    FileManager(string filename = "phone_book.txt");
    ~FileManager();

    bool saveToFile(const list<Contact>& contact_book);
    list<Contact> loadFromFile(const list<Contact>& contact_book);

    string getFileName() const;
};