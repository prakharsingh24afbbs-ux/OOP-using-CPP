#include <iostream>

class List{ //abstract class
protected:
	int Arr[10];
    int last=0;
public:
	List() : last(-1) {std::cout<<"List class has been constructed!"<<std::endl;}
    virtual void store(int ele)=0;
    virtual int retrieve()=0;
    virtual ~List() {std::cout<<"List class has been destructed!"<<std::endl;}
};
class Stack : public List {
public:
    void store(int ele){
        if(last>=9){
            std::cout<<"Stack overflow :("<<std::endl;
            return;
        }
		Arr[++last]=ele;
	}
    int retrieve(){
		if(last==-1){
            std::cout<<"Stack underflow :("<<std::endl;
            return -1;
        }
		return Arr[last];
	}
};
class Queue : public List{
// Arr[0] is the front, and last is the rear.
public:
	void store(int ele){
        if(last>=9){
            std::cout<<"Queue overflow :("<<std::endl;
            return;
        }
        Arr[++last]=ele;
    }
    int retrieve(){
        if(last==-1){
            std::cout<<"Queue underflow :("<<std::endl;
            return -1;
        }
        int front=Arr[0];
        for(int i=1; i<=last; i++){
            Arr[i-1]=Arr[i];
        }
        last--;
        return front;
    }
};

int main(){
	Stack stack;
	stack.store(10);
	stack.store(30);
	stack.store(5);
	std::cout<<"Stack top: "<<stack.retrieve()<<std::endl;

	Queue queue;
	queue.store(10);
	queue.store(30);
	queue.store(5);
	std::cout<<"Queue front: "<<queue.retrieve()<<std::endl;
	std::cout<<"Queue front: "<<queue.retrieve()<<std::endl;
	std::cout<<"Queue front: "<<queue.retrieve()<<std::endl;
	std::cout<<"Queue after empty: "<<queue.retrieve()<<std::endl;
	return 0;
}