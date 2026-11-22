#include <iostream>
using namespace std;

int arr[2][6]= {4,5,6,1,3,1,2,1,3,6,3,6};

void Process(int a, int b, int c, int *r1, int *r2, int *r3){
	int cnt = 0;
	for(int i = 0 ; i < 2 ; i++) {
		for(int j = 0; j < 6; j++){
			if(arr[i][j]==a)
				(*r1)++;
			else if(arr[i][j]==b)
				(*r2)++;
			else if(arr[i][j]==c){
				(*r3)++;
			}
		}
	}
}

void Input(int &a, int &b, int &c){
	cin >> a >> b >> c;
}

void Output(int &a){
	cout << a << "\n";
}

int main(){
	int a, b, c, r1=0, r2=0, r3=0;
	Input(a, b, c);
	Process(a, b, c, &r1, &r2, &r3);
	Output(r1);
	Output(r2);
	Output(r3);
}
