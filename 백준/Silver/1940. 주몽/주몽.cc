#include <bits/stdc++.h>
using namespace std;

int N, M, arr[15004];
int ret;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> M;
    
    /*if(M > 200000) {
        cout << 200000;
        exit(0);
    }*/
    
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if(arr[i] + arr[j] == M){
                ret++;
            }
        }
    } 
    
    cout << ret;
    
        
}