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
    static map<string, function<string()>> v_table;

    Base(const string _sub) : sub(_sub){};

    string test() {
        if ("" != sub) {
            return v_table.at(sub)();
        } else {
            return "from base";
        }
    }
};

class SubA {
public:
    operator Base() const {
        if (!Base::v_table.contains("SubA")) {
            Base::v_table.emplace("SubA", []() { return "from SubA"; });
        }
        return Base("SubA");
    }
};

#endif /* IMPLICIT_H */
