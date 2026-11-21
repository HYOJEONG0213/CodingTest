#include <iostream>
using namespace std;

char scoring(){
	int a;
	cin >> a;
	if(a>=90) return 'A';
	else if(a>=80) return 'B';
	else if(a>=70) return 'C';
	else return 'D';
}

int main(){
	cout << scoring();
}
