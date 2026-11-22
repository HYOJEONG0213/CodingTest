#include <iostream>
using namespace std;

struct PROFILE{
	char name[7];
	int age;
	int weight;
};

int main(){
	PROFILE int1, int2;
	cin >> int1.name >> int1.age >> int1.weight;
	cin >> int2.name >> int2.age >> int2.weight;
	cout << int1.name << "&" << int2.name <<"\n";
	cout << (int1.age + int2.age)/2 << "\n";
	cout << (int1.weight + int2.weight)/2;
}
