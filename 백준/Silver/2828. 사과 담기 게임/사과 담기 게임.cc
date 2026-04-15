#include <bits/stdc++.h>
using namespace std;

int N, M, j, _left = 1, _right = 0, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> j;
    for(; j > 0; j--) {
        int a;
        cin >> a;
        _right = _left + M - 1;
        if(a < _left){
            ret += _left - a;
            _left = a;
        }
        
        if(a > _right){
            ret += a - _right;
            _right = a;
            _left = a - M + 1;
        }
    }
    
    
    cout << ret;
    
    

    
}