// O(n/2)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int flag=0;
    if(n == 1) {
        cout << "Not Prime Number" << endl;
    }
    else {
        for(int i=2;i<=n/2;i++) {
            if(n%i==0) {
                flag=1;
                break;
            }
        }
        if(flag==0) {
            cout << "Prime Number" << endl;
        }
        else {
            cout << "Not Prime Number" << endl;
        }
    }
    return 0;
}