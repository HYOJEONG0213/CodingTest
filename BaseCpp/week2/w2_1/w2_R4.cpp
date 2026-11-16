#include <iostream>
using namespace std;

int arr[5], a;


int main(){
	cin >> a;
	for(int i = 0; i < 5; i++){
		arr[i] = a--;
		cout << arr[i];
	}
	
}
