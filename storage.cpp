#include <iostream>
#include <string>
#include "date.h"
#include <map>
#include <fstream>

#include "base64.h"
#include "storage.h"
using namespace std;


    string Storage::base64_encode_wr(string original) {
        return base64_encode(reinterpret_cast<const unsigned char*>(original.c_str()), original.length());
    }

    Storage::~Storage() {
        save();
    }

    void Storage::add_data(string task) {
        storage[iterator++] = base64_encode_wr(task);
        cout << "Элемент " << task << " добавлен успешно!" << endl;
    }
    void Storage::delete_data(string task) {
        int key;
        for (auto i : storage) {
            if (i.second == base64_encode_wr(task))
                key = i.first;
        }
        storage.erase(key);
        cout << "Удален элемент успешно!" << endl;
    }

    void Storage::print() {
        for (auto i : storage) {
            cout << i.first << "\t" << base64_decode(i.second) << "\t" << endl;
        }
    }

    void Storage::save() {
        ofstream bout("storage_img" + Date::now().str() + ".bin", ios::binary);
        for (auto i : storage) {
            bout << i.first << "\t" << i.second << "\t" << endl;
        }
        cout << "saving in bin success!" << endl;
        bout.close();
    }

    void Storage::load(string filename) {
        ifstream bin(filename);
        int i;
        string str;
        while (bin)
        {
            bin >> i >> str;
            storage[i] = str;
        }
        bin.close();
    }
