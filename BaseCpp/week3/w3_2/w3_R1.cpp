#include <iostream>
using namespace std;

int A[5] = {2,1,2,4,5};
int B[3][3] = {2,5,3,4,5,7,8,7,2};
int a, cnt;

int main(){
	cin >> a;
	for(int i = 0 ; i < 5; i ++){
		if(A[i]==a) cnt++;
	}
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j < 3; j++){
			if(B[i][j] == a) cnt++;
		}
	}
	
	cout << cnt;
}
