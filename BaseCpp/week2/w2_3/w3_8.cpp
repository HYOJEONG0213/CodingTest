#include <iostream>
using namespace std;

int arr[3][3] = {3,4,1,2,1,4,3,3,0};
int even, odd;

int main(){
	for(int i = 0 ; i < 3; i ++){
		for(int j = 0 ; j < 3; j++){
			if(arr[i][j]%2==1) odd++;
			else even++;
		}
	}
	cout << even << "  " << odd;
}
