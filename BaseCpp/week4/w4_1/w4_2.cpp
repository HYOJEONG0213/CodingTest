#include <iostream>
using namespace std;

char arr[3][3] = {'A','D','F','Q','W','E','Z','X','C'}, a;

void Find(char *p, int  *rety, int *retx){
	for(int i = 0; i < 3; i++){
		for(int j = 0 ; j < 3; j++){
			if(arr[i][j]==*p){
				*rety = i;
				*retx = j;
				return;
			}
		}
	}
}

int main(){
	cin >> a;
	int rety, retx;
	Find(&a, &rety, &retx);
	cout << rety << " " << retx;
}
