#include <iostream>
using namespace std;


void BBQ(int a, int b){
	cout << a+b<<"\n" << a-b << "\n" << a*b << "\n" << a/b;
	
}

int main(){
	int a, b;
	cin >> a >> b;
	BBQ(a, b);
}
