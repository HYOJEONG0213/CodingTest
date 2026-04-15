#include <bits/stdc++.h>
using namespace std;
int N, M, K, A[14][14], board[14][14], x, y, z, ret;
int dy[8] = {-1,-1,-1,0,1,1,1,0}, dx[8] = {-1,0,1,1,1,0,-1,-1};
vector <int> tree[14][14];

void showTree(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(tree[i][j].size()==0) continue;
			
			for(int k : tree[i][j]){
				cout << k << " ";
			}
			cout << "\n";
		}
	}
}

void spring(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(tree[i][j].size()==0) continue;
			
			int die = 0;
			sort(tree[i][j].begin(), tree[i][j].end());
			for(int k = 0; k < tree[i][j].size(); k++){
				int tr = tree[i][j][k];
				//cout << tr << " ";
				
				if(board[i][j] - tr >= 0){
					board[i][j] -= tr;
					tree[i][j][k]++;
				}
				else{
					for(int kk = k; kk < tree[i][j].size(); kk++){
						die += tree[i][j][kk]/2;
					}
					
					tree[i][j].erase(tree[i][j].begin()+k, tree[i][j].end());
					break;
				}
			}
			
			board[i][j] += die;
		}
	}
	//showTree();
}

void fall(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(tree[i][j].size()==0) continue;
			
			for(int k : tree[i][j]){
				if(k%5 == 0){
					for(int dir = 0; dir < 8; dir++){
						int ny = i + dy[dir];
						int nx = j + dx[dir];
						if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}	
	}
	//cout << "Fall"<<"\n";
	//showTree();
}

void winter(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			board[i][j] += A[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < M; i++){
		cin >> x >> y >> z;
		x--; y--;
		tree[x][y].push_back(z);
	}
	fill(&board[0][0],&board[0][0]+14*14, 5);
	
	while(K--){
		spring();
		fall();
		winter();
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ret += tree[i][j].size();
		}
	}
	
	cout << ret;
}