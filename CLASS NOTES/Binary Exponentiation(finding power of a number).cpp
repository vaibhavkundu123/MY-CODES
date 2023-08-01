#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    while(k > 0) {
        if(k%2 == 1) {
            ans *= n;
            k = k - 1;
        }
        else {
            n *= n;
            k = k/2;
        }
    }
    cout << ans << endl;
    return 0;
}