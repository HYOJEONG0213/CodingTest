#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
int N;
vector <int> A, temp;
ll ret;

void merge(int s, int mid, int e){
	int i = s;	// 왼쪽 그룹 
	int j = mid + 1;	//오른쪽 그룹
	int k = s;
	
	while(i <= mid && j <= e){
		if(A[i] <= A[j]){
			temp[k] = A[i];
			k++; i++;
		}
		else{
			ret += mid - i + 1;
			temp[k] = A[j];
			k++; j++;
		}
	} 
	
	while(i <= mid) {
		temp[k] = A[i];
		k++; i++;
	}
	while(j <= e){
		temp[k] = A[j];
		k++; j++;
	}
	
	for(int i = s; i <= e; i++)
		A[i] = temp[i];
}

void mergeSort(int s, int e){
	if(s < e){
		int mid = (s+e)/2;
		mergeSort(s, mid);
		mergeSort(mid+1, e);
		merge(s, mid, e);
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(500004);
	temp.resize(500004);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	mergeSort(0, N-1);
	
	cout << ret;
}