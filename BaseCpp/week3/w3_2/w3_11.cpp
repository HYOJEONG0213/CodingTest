#include <iostream>
using namespace std;

struct Person{
	int age;
	int height;
};
Person a, b;

void Input(){
	cin >> a.age >> a.height >> b.age >> b.height;
}

void Output(){
	cout << (a.age+b.age)/2 << " ";
	cout << (a.height+b.height)/2 << "\n";
}

int main(){
	Input();
	Output();
}
