#include <iostream>
using namespace std;

int A[5] , B[5] ,C[5], Ret[5] ;

int main(){
	for(int i = 0 ; i < 5; i++) cin >> A[i];
	for(int i = 0 ; i < 5; i++) cin >> B[i];
	for(int i = 0 ; i < 5; i++) cin >> C[i];
	
	for(int i = 0 ; i < 5; i++){
		Ret[i] = A[i]*B[i] + C[i];
		cout << Ret[i] << " ";
	}
}
