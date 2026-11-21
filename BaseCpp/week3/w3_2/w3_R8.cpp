#include <iostream>
using namespace std;

int a, b;
char c;

void BBQ(int num){
	for(int i = 1; i <= num ;i++) cout << i << " ";
}

void KFC(char num){
	for(int i = 0 ; i < 7; i++) cout << num << " ";
}

int main(){
	cin >> a;
	if(a%2 == 1){
		cin >> b;
		BBQ(b);
	}
	else{
		cin >> c;
		KFC(c);
	}
}
