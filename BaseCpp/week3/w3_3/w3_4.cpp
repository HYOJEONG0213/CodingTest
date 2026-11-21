#include <iostream>
using namespace std;

int a, b;

void printData(int value){
	cout << value << "\n";
}

void even(int value){
	printData(value*2);
}

void odd(int value){
	printData(value-10);
}

int main(){
	cin >> a >> b;
	if((a/b)%2==0) even(a/b);
	else odd(a/b);
	
	printData(a+b);
}
