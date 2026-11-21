#include <iostream>
using namespace std;

char arr[7] = {'A', '1', '1', '1', '5', 'A', 'w'};
char c;
int cnt;

int main(){
	cin >> c;
	for(int i = 0 ; i < 7; i++){
		if(arr[i] == c) cnt++;
	}
	if(cnt >= 3) cout << "THREE";
	else if(cnt == 2) cout << "TWO";
	else if(cnt == 1) cout << "ONE";
	else cout << "NOTHING";
}
