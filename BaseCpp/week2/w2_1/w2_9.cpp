#include <iostream>
using namespace std;

char arr[3] = {'A', 'B', 'C'};
int a;

void KFC(){
	for(int i = 0 ; i < 3 ; i++) cout << arr[i];
	cout << "\n";
} 

int main(){
	cin >> a;
	for(int i = 0 ; i < a; i ++) KFC();
}
