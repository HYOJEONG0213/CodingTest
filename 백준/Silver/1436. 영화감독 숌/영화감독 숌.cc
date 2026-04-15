#include <bits/stdc++.h>
using namespace std;

int n, sum ;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    
    for(int i = 1;; i++){
        if(to_string(i).find("666") != string::npos) n--;
        if(n == 0) {
            cout << i;
            break;
        }
    }
    
    
}