#pragma once

class Resource {
private:
    int value;
public:
    Resource() {
        value = 0;
    }
    void reset() {
        value = 0;
    }
    int getValue() const {
        return value;
    }
    void setValue(int number) {
        value = number;
    }
};