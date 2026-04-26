#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
struct Tree{
	int x, y, len;
	bool operator <(const Tree &other) const{
		return len > other.len;
	}
};
int N, a, b, c, ret = 100;
vector <Tree> A;

int getlen(Tree &a, Tree &b){
	int len1 = abs(b.x-a.x);
	int len2 = abs(b.y-a.y);
	return len1*2+len2*2;
}

int getLen(Tree &a, Tree &b){
	// 총 둘레  
	int sum = getlen(a, b);
	// 안에 포함되는 나무 수 
	int tempsum = 0;
	int cnt = 0;
	vector <Tree> e;	// 울타리 외부 
	vector <Tree> in;	// 울타리 내부  
	
	int maxX = max(a.x, b.x);
	int minX = min(a.x, b.x);
	int maxY = max(a.y, b.y);
	int minY = min(a.y, b.y);
	
	for(auto i : A){
		// 울타리 내부 외부 구분
		if((i.x >= minX && i.y >= minY) && (i.x <= maxX && i.y <= maxY)) {
			in.push_back(i);
		}
		else{
			e.push_back(i);
			tempsum += i.len;
			cnt++;
		}
	}
	
	if(tempsum < sum){
		for(auto i : in){
			tempsum += i.len;
			cnt++;
			if(tempsum >= sum) break;
		}
	}
	
	if(tempsum < sum) return 100;
	else return cnt;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Tree t;
	for(int i = 0; i < N; i++){
		cin >> t.x >> t.y >> t.len;
		A.push_back(t);
	}
	sort(A.begin(), A.end());
	
	// i : 왼, j : 오, k: 위, l : 아래  
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				for(int l = 0; l < N; l++){
					Tree p1 = {A[i].x, A[k].y, 0};
					Tree p2 = {A[j].x, A[l].y, 0};
					ret = min(ret, getLen(p1, p2));
				}
			}
			
		}
	}
	
	cout << (ret==100 ? 0 : ret);
}