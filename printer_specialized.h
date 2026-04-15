#ifndef PRINTER_SPECIALIZED_H
#define PRINTER_SPECIALIZED_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>

struct printer {
    static void print(const T& valor) {
        cout << valor << endl;
    }
};

template <>

struct printer<bool> {
    static void print(bool valor) {
        cout << (valor ? "true" : "false") << endl;
    }
};

template <typename T>

struct printer<vector<T>> {
    static void print(const vector<T>& vecti) {
        cout << "[";
        for (const auto& item : vecti)
            cout << item << "  ";
        cout << "]" << endl;
    }
};

#endif
