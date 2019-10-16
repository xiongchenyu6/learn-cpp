#ifndef IMPLICIT_H
#define IMPLICIT_H

#include <functional>
#include <iostream>
#include <map>

using namespace std;
class Base {
private:
    const string sub = "";

public:
    static map<string, function<void()>> v_table;

    Base(const string _sub) : sub(_sub){};

    void test() {
        if ("" != sub) {
            v_table.at(sub)();
        } else {
            cout << "from base"
                 << "\n";
        }
    }
};

map<string, function<void()>> Base::v_table;

class SubA {
public:
    operator Base() const {
        if (!Base::v_table.contains("SubA")) {
            Base::v_table.emplace("SubA", []() {
                cout << "from SubA"
                     << "\n";
            });
        }
        return Base("SubA");
    }
};

#endif /* IMPLICIT_H */
