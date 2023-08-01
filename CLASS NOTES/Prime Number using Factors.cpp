// O(root(n))

#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n%i == 0) {
            if(i != n/i) {
                count += 2;
            }
            else {
                count++;
            }
        }
    }
    if (count == 2) { 
        cout << "Prime" << endl;
    }
    else{ 
        cout << "Not Prime" << endl;
    }
    return 0;
}