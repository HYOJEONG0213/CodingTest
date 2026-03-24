#include <bits/stdc++.h>
using namespace std;

int N;
int A[4004], B[4004], C[4004], D[4004];
long long ret;
unordered_map<int, int> AB;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    AB.reserve(N * N);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            AB[A[i] + B[j]]++;
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int target = -(C[i] + D[j]);
            
            if (AB.count(target)) {
                ret += AB[target];
            }
        }
    }
    
    cout << ret << "\n";
    return 0;
}