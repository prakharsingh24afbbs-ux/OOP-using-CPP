#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){
	ifstream fileRead("Hi.txt");
	ofstream fileWrite("Bye.txt");
	
	if(!fileRead || !fileWrite){
		cout<<"Error opening the file..."<<endl;
		return 1;
	}
	char ch;
	
	while(fileRead.get(ch)){
		if(!isspace(ch)){
			fileWrite.put(ch);
		}
	}
	fileRead.close();
	fileWrite.close();
	cout<<"Removed whitespaces removed. "<<endl;
	return 0;
}
