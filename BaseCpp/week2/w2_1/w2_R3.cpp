#include <iostream>
using namespace std;

int arr1[5], arr2[5];
int a, b;


int main(){
	cin >> a >> b;
	for(int i = 0 ; i <5; i++) arr1[i] = a;
	for(int i = 0 ; i <5; i++) arr2[i] = b;
	for(int i = 0 ; i <5; i++) cout << arr1[i] ;
	cout << "\n";
	for(int i = 0 ; i <5; i++) cout << arr2[i] ;
}

