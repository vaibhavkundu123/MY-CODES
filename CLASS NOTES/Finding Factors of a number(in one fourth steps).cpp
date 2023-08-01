#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i;
    for(i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            if(i != n/i) {
                cout << i << " " << n/i << " ";
            }
            else {
            cout << i << " ";
            }
        }
    }
    cout << endl;
    return 0;
}