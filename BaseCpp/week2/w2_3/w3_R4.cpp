#include <iostream>
using namespace std;

char arr[3][5], a;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			arr[i][j] = a++;
		}
	}
	
	cout << char(arr[2][2] - 'A' + 'a');
}
