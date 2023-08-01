#include<bits/stdc++.h>
using namespace std;

int main() {
    int left = 1, right;
    cin >> right;
    vector<int> prime_sieve(right + 1,0);
    prime_sieve[0] = 1;
    prime_sieve[1] = 1;

    // O(n/2)

    /* for(int index = 2; index <= right/2; index++) {
        if(prime_sieve[index] == 0) {
            for(int multiple = index * 2; multiple <= right; multiple += index) {
                if(prime_sieve[multiple] == 0) {
                    prime_sieve[multiple] = 1;
                }
            }
        }
    } */

    // O(root(n))

    /* for(int index = 2; index * index <= right; index++) {
        if(prime_sieve[index] == 0) {
            for(int multiple = index * index; multiple <= right; multiple += index) {
                if(prime_sieve[multiple] == 0) {
                    prime_sieve[multiple] = 1;
                }
            }
        }
    } */

    for(int index = 2; index <= right; index++) {
        if(prime_sieve[index] == 0) {
            cout << index << " ";
        }
    }
    cout << endl;

    return 0;

}