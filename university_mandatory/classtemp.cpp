#include <iostream>
#include <string>

template <class T>
class Compare{
	T a, b;
public:
	Compare(T n, T m) : a(n), b(m){
		std::cout<<"Object constructed."<<std::endl;
	}
	~Compare(){
		std::cout<<"Object destructed."<<std::endl;
	}	
	T LargerVal(){
		return a>b ? a : b;
	}	
}; 

int main(){
	Compare<int> objInt(3, 7);
	Compare<double> objDouble(19.578, 0.6767);
	Compare<std::string> objStr("this", "that");
	std::cout<<"Larger int value is "<<objInt.LargerVal()<<std::endl;
	std::cout<<"Larger double value is "<<objDouble.LargerVal()<<std::endl;
	std::cout<<"Larger string value is of "<<objStr.LargerVal()<<std::endl;
	return 0;
}