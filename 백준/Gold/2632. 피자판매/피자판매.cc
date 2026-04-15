//rotate에 출력부분만 바꾼 버전  
#include <bits/stdc++.h>
using namespace std;

int X, m, n, ret, A[1004], B[1004], psumA[2004], psumB[2004];
map <int, int> mapA, mapB;

void go(int N, int psum[], map <int, int> &m){
	for(int interval = 1; interval <= N; interval++){
		for(int start = interval; start <= N + interval - 1; start++){
			int temp = psum[start] - psum[start-interval];
			m[temp]++;
			
			if(interval == N) break;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	cin >> X;
	cin >> m >> n;
	
	for(int i = 1; i <= m; i++){
		cin >> A[i];
		psumA[i] = psumA[i-1] + A[i];
	}
	for(int i = 1; i <= m; i++){
		psumA[m + i] = psumA[m+i-1] + A[i];
	}
	
	//for(int i : psumA) cout << i << " ";
	
	for(int i = 1; i <= n; i++){
		cin >> B[i];
		psumB[i] = psumB[i-1] + B[i];
	}
	for(int i = 1; i <= n; i++){
		psumB[n + i] = psumB[n+i-1] + B[i];
	}
	
	//for(int i : psumB) cout << i << " ";
	
	go(m, psumA, mapA);
	go(n, psumB, mapB);
	
	ret += mapA[X] + mapB[X];
	
	for(int i = 1; i < X; i++){
		ret += (mapA[i] * mapB[X - i]);
	}
	
	cout << ret;
}