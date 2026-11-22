#include <iostream>
using namespace std;

char c, arr[3][3];

int main(){
	cin >> c;
	int i = 2;
	while(i >= 0){
		int j = 0;
		while(j < 3-i){
			arr[i][j] = c++;
			j++;
		}
		i--;
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0 ;j  < 3; j++){
			cout << arr[i][j] ;
		}
		cout << "\n";
	}
}
