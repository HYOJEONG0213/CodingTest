#include <iostream>
using namespace std;

int arr[11] = {3,4,1,5,8,1,7,7,3,6,9}, a;

int main(){
	cin >> a;
	for(int i = 0; i < 11; i+= a){
		cout << arr[i] << " ";
	}
}
