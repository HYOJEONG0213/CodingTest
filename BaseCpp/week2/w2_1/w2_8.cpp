#include <iostream>
using namespace std;

int a;

void KFC(){
	cin >> a; 
}

void BBQ(int num){
	if(num > 5) cout << "만세";
	else cout << "다시";
}


int main(){
	KFC();
	BBQ(a);
}
