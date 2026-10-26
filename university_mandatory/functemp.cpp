#include <iostream>

template <typename T>
T squareOf(T a){
	return a*a;
}

int main(){
	std::cout<<"Square of int is "<<squareOf(4)<<std::endl;
	std::cout<<"Square of float is "<<squareOf(7.2f)<<std::endl;
	std::cout<<"Square of double is "<<squareOf(8.235)<<std::endl;
	return 0;
}
