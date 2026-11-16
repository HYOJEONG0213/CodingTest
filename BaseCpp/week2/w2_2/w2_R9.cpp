#include <iostream>
using namespace std;

int arr[6] = {5,4,1,2,7,8}, a;

int main(){
	cin >> a;
	for(int i = 0 ; i < a; i++){
		for(int j = 5; j >= 0; j--){
			cout << arr[j];
		}
		cout << "\n";
	}
}
