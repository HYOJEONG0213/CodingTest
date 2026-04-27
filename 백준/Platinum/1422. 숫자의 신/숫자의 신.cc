#include <bits/stdc++.h>
using namespace std;

int K, N;
int A[104];
string B[104], pivot;

bool compare(string a, string b){
	return a+b > b+a;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	for(int i = 0; i < K; i++){
		cin >> A[i];
	}
	sort(A, A+K, greater<int>());
	pivot = to_string(A[0]);
	for(int i = 0; i < K; i++){
		B[i] = to_string(A[i]);
	}
	for(int i = K; i < N; i++){
		B[i] = pivot;
	}
	sort(B, B+N, compare);
	for(auto i : B){
		cout << i;
	}
}