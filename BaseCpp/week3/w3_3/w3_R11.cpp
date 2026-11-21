#include <iostream>
using namespace std;

int arr[4][4] = {1,3,6,2,4,2,4,5,6,3,7,3,1,5,4,6}, a; 
int select[16], s;

int main(){
	cin >> a;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(arr[i][j] > a){
				select[s++] = arr[i][j];
			}
		}
	}
	
	for(int i = 0; i < s; i++) cout << select[i] << " ";
}
