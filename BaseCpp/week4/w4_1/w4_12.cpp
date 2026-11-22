#include <iostream>
using namespace std;

int arr[4][4] = {3,4,1,6,3,5,3,6,0,0,0,0,5,4,6,0};

int main(){
	for(int i = 0 ; i < 4; i++) cin >> arr[2][i];
	
	int mx = arr[0][0], mn = arr[0][0];
	int mxY = 0, mxX = 0, mnY = 0, mnX = 0;
	for(int i = 0 ; i < 4; i++){
		for(int j = 0 ; j < 4; j++){
			if(mx < arr[i][j]){
				mx = arr[i][j];
				mxY = i, mxX = j;
			}
			else if(mn > arr[i][j]){
				mn = arr[i][j];
				mnY = i, mnX = j;
			}
		}
	}
	 
	cout << mx << " " << mxY << " " << mxX <<"\n";
	cout << mn << " " << mnY << " " << mnX;
}
