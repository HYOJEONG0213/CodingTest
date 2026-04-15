#include <bits/stdc++.h>
using namespace std;

int N, M, T, x, d, k, ret, a;
vector <vector <int>> board;
vector <int> v;

void show(){
	for(int i = 0 ; i < N ; i ++){
		for(int j = 0 ; j  <M ; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void adjcheck(){
	vector <pair<int,int>> changeList;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0; j < M ; j ++){
			if(board[i][j] == -1) continue;
			
			if(board[i][j] == board[i][(j+1)%M]){
				changeList.push_back({i,j});
				changeList.push_back({i,(j+1)%M});
			}
			if(i+1 < N && board[i][j] == board[i+1][j]){
				changeList.push_back({i,j});
				changeList.push_back({i+1,j});
			}
		}
	}
	
	//그 판에서 인접하면서 같은 수가 없다면  
	if(changeList.size()==0){
		double sum = 0;
		double num = 0;
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M ; j ++){
				if(board[i][j]== -1) continue;
				sum += board[i][j];
				num++;
			}
		}
		double avg = sum/num;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M ; j ++){
				if(board[i][j]== -1) continue;
				if(board[i][j] > avg) board[i][j]--;
				else if(board[i][j] < avg) board[i][j]++;
			}
		}
	}
	
	for(auto i : changeList){
		int y, x;
		tie(y, x) = i;
		board[y][x] = -1;
	}
	
	//show();
}

//x배수의 원판을 d 방향으로(1은 반시계) k칸 회전 
void go(int x, int d, int k){
	for(int i = x; i <= N; i+= x){
		if(d == 1){
			rotate(board[i-1].begin(), board[i-1].begin()+k, board[i-1].end());
		}
		else{
			rotate(board[i-1].begin(), board[i-1].begin()+M-k, board[i-1].end());

		}
	}
}



void check(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j] == -1) continue;
			ret += board[i][j];
		}
	}
} 



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T;
	for(int i = 0 ; i < N ; i ++){
		v.clear();
		for(int j = 0 ; j  <M ; j++){
			cin >> a;
			v.push_back(a);
		}
		board.push_back(v);
	}
	for(int i = 0 ; i < T; i++){
		cin >> x >> d >> k;
		go(x, d, k);
		//show();
		adjcheck();
	}
	
	check();
	cout << ret;
}