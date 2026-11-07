#include <iostream>
#include <stdexcept>

class SafeArray{
	int arr[10];
public:
	SafeArray(){ //comstructor, initializes values at all indices to 0
		for(int i=0; i<10; i++){
			arr[i]=0;
		}
	}
	void set(int index, int value){
		if(index<0 || index>=10){
			throw std::out_of_range("Index is out of bound (Valid index: 0 to 9)");
		}
		arr[index]=value;
	}
	int get(int index){
		if(index<0 || index>=10){
			throw std::out_of_range("Index is out of bound (Valid index: 0 to 9)");
		}
		return arr[index];
	}
};

int main(){
	SafeArray array1;
	try{
		std::cout<<"Attempting valid set operation. \n";
		array1.set(2, 20); 
		std::cout<<"Attempting valid get operation. \n";
		std::cout<<"Value at the valid index: "<<array1.get(2)<<"\n\n";
	}
	catch (std::out_of_range& exc){
		std::cout<<"Caught exception: "<<exc.what();
	}
	
	try{
		std::cout<<"Attempting invalid set operation. \n";
		array1.set(11, 100);
	}
	catch (std::out_of_range& exc){
		std::cout<<"Caught exception: "<<exc.what();
	}
	return 0;
}