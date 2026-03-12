#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
const int MAXNUM = 1000000000;
int N, A[500004], ret[500004], tree[500004];
vector <pp> player, temp(500004);

void mergeSort(int s, int mid, int e){
	int i = s, j = mid+1, k = s;
	while(i <= mid && j <= e){
		if(player[i].first < player[j].first){
			ret[player[j].second] += mid - i + 1;
			temp[k++] = player[j++];
		}
		else{
			temp[k++] = player[i++];
		}
	}
	
	while(i<=mid){
		temp[k++] = player[i++];
	}
	while(j<=e){
		temp[k++] = player[j++];
	}
	
	for(int i = s; i <= e; i++){
		player[i] = temp[i];
	}
}


void merge(int s, int e){
	if(s >= e) return;
	
	int mid = (s+e)/2;
	merge(s, mid);
	merge(mid+1, e);
	mergeSort(s, mid, e);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	player.push_back({0, 0});
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		player.push_back({A[i], i});
	}
	
	merge(1, N);
	
	for(int i = 1; i <= N; i++){
		cout << i - ret[i] << "\n";
	}
}