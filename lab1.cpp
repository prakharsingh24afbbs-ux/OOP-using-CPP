#include <iostream>

class Rectangle {
    int length;
    int breadth;
public:
    Rectangle() {
        length = 0;
        breadth = 0;
    }
    Rectangle(int length, int breadth) {
        this->length = length;
        this->breadth = breadth;
    }
    void setLength(int length) {
        this->length = length;
    }
    void setBreadth(int breadth) {
        this->breadth = breadth;
    }
    int area(){
        return length * breadth;
    }
    int perimeter(){
        return 2 * (length + breadth);
    }
    void show(){
        std::cout<<"Length: " << length << ", Breadth: " << breadth << std::endl;
    }
};
int main() {
    Rectangle r1;
    r1.show();
    Rectangle r2(5, 10);
    r2.show();
    std::cout<<"Area of object r2: "<<r2.area()<<std::endl;
    std::cout<<"Perimeter of object r2: "<<r2.perimeter()<<std::endl;
    return 0;
}