#include <iostream>
using namespace std;

char arr[3][10];

int main(){
	for(int i = 0; i < 3; i++){
		cin >> arr[i];
	}
	for(int i = 0 ; i < 3 ; i++){
		int j = 0;
		while(arr[i][j] != '\0')
			j++;
		cout << j << "\n";
	}
}
