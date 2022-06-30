#pragma once
#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <map>
using namespace std;

class Storage {
private:
    map<int, string> storage;
    int iterator = 0;
    string base64_encode_wr(string original);
public:
    ~Storage();
    void add_data(string task);
    void delete_data(string task);
    void print();
    void save();
    void load(string filename);
};


#endif // !STORAGE_H
