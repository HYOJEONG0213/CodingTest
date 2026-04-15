#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int a, b;
int cnt[101];
int sum;
//시각은 이상, 미만  

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B >> C;
	for(int i =0; i<3; i++){
		cin >> a >> b;
		for(int j = a; j < b; j++) cnt[j]++;
	}
	
	for(int j = 0; j < 100; j++){
		if(cnt[j]){
			if(cnt[j]==1){
				sum += A;
			}
			else if(cnt[j]==2){
				sum += B * 2;
			}
			else if(cnt[j]==3){
				sum += C * 3;
			}
		}
	}
	
	cout << sum;
}