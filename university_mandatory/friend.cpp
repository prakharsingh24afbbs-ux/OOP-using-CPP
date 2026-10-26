#include <iostream>
class Memory;
class CPU{
	float utilization;
public:
	CPU(float u) : utilization(u){}
	friend void whichTask(const CPU& c, const Memory& m);
};

class Memory{
	float utilization;
public:
	Memory(float u) : utilization(u){}
	friend void whichTask(const CPU& c, const Memory& m);
};

void whichTask(const CPU& c, const Memory& m){
	if(c.utilization>m.utilization){
		std::cout<<"Ran memory intensive task"<<std::endl;
	}
	else if(c.utilization<m.utilization){
		std::cout<<"Ran CPU intensive task"<<std::endl;
	}
	else{
	std::cout<<"No task has been ran."<<std::endl;
	}
}

int main(){
	CPU c(45.7);
	Memory m(50);
	whichTask(c,m);
	return 0;
}