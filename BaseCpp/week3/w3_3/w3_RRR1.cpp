#include <iostream>
using namespace std;

char arr[6] = {'D', 'F', 'G', 'D', 'A', 'Q'}, a, b;

int main(){
	cin >> a >> b;
	for(int i = 0 ; i < 6; i++){
		if(arr[i] >= a && arr[i] <= b) {
			cout << "발견!";
			return 0;
		} 
	}
	
	cout << "미발견!";
}
