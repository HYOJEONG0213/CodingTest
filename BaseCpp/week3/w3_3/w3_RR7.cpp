#include <iostream>
using namespace std;

int arr[7][5] = {1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,0};

int INPUT(){
	int a;
	cin >> a;
	return a;
}

void OUTPUT(int a){
	cout << a;
}

void PROCESS(int a){
	int cnt = 0;
	for(int i = 0; i < 7; i++){
		if(arr[i][a] == 1) cnt++;
	}
	OUTPUT(cnt);
}




int main(){
	PROCESS(INPUT());
}
