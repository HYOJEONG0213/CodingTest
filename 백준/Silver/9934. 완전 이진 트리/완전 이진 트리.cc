#include <bits/stdc++.h>
using namespace std;

int arr[2000], k;
vector <int> result[14];


void dfs(int start, int end, int level){
    if(start > end) return;
    if(start == end) {
        result[level].push_back(arr[start]);
        return;
    }

    int mid = (end+start) / 2;
    result[level].push_back(arr[mid]);
    dfs(start, mid - 1, level+1);
    dfs(mid + 1, end, level+1);
    
    return;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> k;
    int end = (int) pow(2, k) -1;
    
    for(int i = 0; i < end ; i ++){
        cin >> arr[i];
    }
    
    dfs(0, end, 0);
    
    for(int i = 0; i < k; i++){
        for(int j : result[i])
            cout << j << " ";
            
        cout << "\n";
    }    
}