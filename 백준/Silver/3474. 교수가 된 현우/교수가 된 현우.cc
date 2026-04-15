#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll N;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        int ret2 = 0, ret5 = 0;
        
        for(int j = 2; j <= N; j*=2){
            ret2 += N / j;    
        }
        for(int j = 5; j <= N; j*=5){
            ret5 += N / j;
        }
        
        
        cout << min(ret2, ret5) << "\n"; 
    }
        
}