#include <iostream>

using namespace std;

class Rectangle {
private:
    int length;
    int height;

public:
    Rectangle(int length, int height);
    double area();
    void changeLength(int length);
    ~Rectangle();
};

int main() {
    Rectangle r(2, 2);

    // r.initialize(2, 2);
    
    double area1 = r.area();
    cout<<area1<<endl;
    
    r.changeLength(4);
    
    area1 = r.area();
    cout<<area1<<endl;

    return 0;
}

Rectangle::Rectangle(int length, int height){
    this->height = height;
    this->length = length;
}

double Rectangle::area() {
    return (double) this->length * this->height;
}

void Rectangle::changeLength(int length) {
    this->length = length;
}

Rectangle::~Rectangle() {}
