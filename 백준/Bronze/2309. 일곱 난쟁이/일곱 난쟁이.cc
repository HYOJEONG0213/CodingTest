//일곱 난쟁이  
#include <bits/stdc++.h>
using namespace std;

int arr[9];

void printV(vector <int> &b){
	for(int i : b)
		cout << i << "\n";
}

void combi(int start, vector <int> &b){
	if(b.size() == 7){
		if(accumulate(b.begin(), b.end(), 0) == 100){
			printV(b);
			exit(0);
		}
	}
	
	for(int i = start+1; i < 9; i++){
		b.push_back(arr[i]);
		combi(i, b);
		b.pop_back();
	}
}

int main(){
	vector <int> v; 
	for(int i = 0; i<9; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+9);
	
	combi(-1, v);
}