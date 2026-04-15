#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B;
    cout << (A + B) * (A - B);
}