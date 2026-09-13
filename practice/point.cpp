#include <iostream>
#include <cmath>

class Point{
    float x;
    float y;
public:
    Point() : x(0), y(0) {}
    Point(float a) : x(a), y(a) {}
    Point(float a, float b) : x(a), y(b) {}
    void show(){
        std::cout<<"("<<x<<","<<y<<")"<<std::endl;
    }
    float distanceFromOrigin(){
        return sqrt(x*x + y*y);
    }
    float distanceFromPoint(Point p){
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    }
};

int main(){
    Point p1;
    p1.show();
    Point p2(4.25);
    p2.show();
    Point p3(3.75, 7.50);
    p3.show();
    std::cout<<"Distance of p2 from origin: "<<p2.distanceFromOrigin()<<std::endl;
    std::cout<<"Distance of p3 from origin: "<<p3.distanceFromOrigin()<<std::endl;
    std::cout<<"Distance of p2 from p3: "<<p2.distanceFromPoint(p3)<<std::endl;
    return 0;
}