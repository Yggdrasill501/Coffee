#define OBJECT_H

class Object {
    char8_t &x;
    signed char &y;
    int &z;

public:
    Object();
    ~Object();
    void print();
};
