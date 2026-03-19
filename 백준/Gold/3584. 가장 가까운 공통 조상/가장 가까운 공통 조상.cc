#include <bits/stdc++.h>
using namespace std;

const int MAXLEVEL = 16;
int T, N, A, B, parent[10004];
bool visited[10004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		memset(parent, 0, sizeof(parent));
		memset(visited, 0, sizeof(visited));

		cin >> N;
		for(int i = 0; i < N-1; i++){
			cin >> A >> B;
			parent[B] = A;
		}
		
		cin >> A >> B;
		
		int here = A;
		while(here != 0){
			visited[here] = true;
			here = parent[here];
		}
		here = B;
		while(here != 0){
			if(visited[here]){
				cout << here << "\n";
				break;
			}
			here = parent[here];
		}
	}
}