#include <iostream>
using namespace std;

char arr[2][6] = {"DATAW","BBQK"};
int a;

int main(){
	cin >> a;
	if(a%2 == 1){
		for(int j = 0 ; j < 6; j++){
			int mn = arr[0][j], mnIdx = j;
			for(int i = j+1; i < 6; i++){
				if(arr[0][i]=='\0') break;
				
				if(mn > arr[0][i]){
					mn = arr[0][i];
					mnIdx = i;
				}
			}
			swap(arr[0][j], arr[0][mnIdx]);
		}
		
	}
	else{
		for(int j = 0 ; j < 6; j++){
			int mn = arr[1][j], mnIdx = j;
			for(int i = j+1; i < 6; i++){
				if(arr[1][i]=='\0') break;
				
				if(mn > arr[1][i]){
					mn = arr[1][i];
					mnIdx = i;
				}
			}
			swap(arr[1][j], arr[1][mnIdx]);
		}
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 6; j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
