#include <iostream>
using namespace std;

int arr[6], a;


int main(){
	cin >> a;
	for(int i = 0 ; i < 6; i++){
		arr[i] = (i+1) * a;
		cout << arr[i] << " ";
	}
}
