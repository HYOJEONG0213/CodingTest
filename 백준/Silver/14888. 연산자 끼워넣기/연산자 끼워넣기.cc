#include <bits/stdc++.h>
using namespace std;

int N, a, mx=-10000000000, mn=1000000000;
vector <int> num, op;

int f(int a, int operand, int b){
	switch(operand){
		case 0:
			return a+b;
		case 1:
			return a-b;
		case 2:
			return a*b;
		case 3:
			return a/b;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N; 
	for(int i = 0 ; i < N ;i++){
		cin >> a;
		num.push_back(a);
	}
	for(int i = 0; i < 4; i++){
		cin >> a;
		while(a--){
			op.push_back(i);
		}
	}
	
	do{
		int sum = num[0];
		for(int i = 0; i < N-1; i++){
			//cout << op[i] << " ";
			sum = f(sum, op[i], num[i+1]);
		}
		//cout << "\n";
		
		mx = max(mx, sum);
		mn = min(mn, sum);
	}while(next_permutation(op.begin(), op.end()));
	
	cout << mx << "\n" << mn;
}