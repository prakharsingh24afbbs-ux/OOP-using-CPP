#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student{
	char name[50];
	int age;
	char sex;
	int height;
	int weight;
public:
	void readData(){
        std::cout << "Enter student's name: ";
        std::cin.ignore(); //clears input buffer
        std::cin.getline(name, 50);
		std::cout<<"Enter student's age: "; std::cin>>age;
		std::cout<<"Enter student's sex: "; std::cin>>sex;
		std::cout<<"Enter student's height (in cm): "; std::cin>>height;
		std::cout<<"Enter student's weight (in lbs): "; std::cin>>weight;
	}
	void show(){
		cout<<"Name: "<<name<<"\nAge: "<<age<<"\nSex: "<<sex<<
		"\nHeight: "<<height<<"\nWeight"<<weight<<endl;
	}
};

int main(){
	Student s;
	s.readData();
	s.show();
	ofstream out("student.dat", ios::binary);
	out.write((char *)&s, sizeof(s));
	out.close();
	
	ifstream in("student.dat", ios::binary);
	Student t;
	in.read((char *)&t, sizeof(t));
	t.show();
	in.close();
	return 0;
}
