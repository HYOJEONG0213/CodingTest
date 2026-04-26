#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector <string> A;

bool compare(string &a, string &b){
	return a+b > b+a;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s;
		A.push_back(s);
	}
	sort(A.begin(), A.end(), compare);
	if(A[0]=="0"){
		cout << 0;
		return 0;
	}
	for(auto i : A){
		cout << i;
	}
}