#include <iostream>

class Shape{
public:
	virtual void describe(){
		std::cout<<"This is just some shape. \n";
	}
}; 

class Rect : public Shape{
public:
	void describe() override{
		std::cout<<"This is a rectangle \n";
	}
};

class Circle : public Shape{
public:
	void describe() override{
		std::cout<<"This is a circle \n";
	}
};

int main(){
	Circle c;
	Shape* shape_ptr= &c;
	shape_ptr->describe();  
	return 0;
}