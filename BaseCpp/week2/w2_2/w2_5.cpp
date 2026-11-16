#include <iostream>
using namespace std;

char arr[4] = {'B','T','K','A'};
int a;

int main(){
	cin >> a;
	for(int i = 0 ; i < a; i++){
		for(int j = 0; j < 4; j++){
			cout << arr[j] << " ";
		}
		cout << "\n";
	}
}
