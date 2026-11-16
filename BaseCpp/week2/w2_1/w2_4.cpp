#include <iostream>
using namespace std;

char arr[3];
int idx;

void KFC(){
	cout << "KFC입니다";
}

void MC(){
	cout << "MC입니다";
}

int main(){
	cin >> idx;
	if(idx == 1){
		KFC();
	} 
	else if(idx == 2){
		MC();
	}
}
