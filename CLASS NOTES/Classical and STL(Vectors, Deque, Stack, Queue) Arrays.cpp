// FOR CLASSICAL ARRAY

/* #include<iostream>
using namespace std;

void Update(int arr[], int i, int updatedval) {
    arr[i] = updatedval;
}

void sizeofarrayupdated(int *arr) {
    cout << "Size of the array outside main " << sizeof(arr) << endl;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int arr[] = {1, 2, 3, 4, 5};

    Update(arr, 1, 50);

    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    cout << "Size of the array in the main function " << sizeof(arr) << endl;

    sizeofarrayupdated(arr);

    return 0;
} */




// FOR STL ARRAY

/* #include<iostream>
#include<array>
using namespace std;

void Update(array<int, 5> &arr, int ind, int updatedval) {
    arr[ind] = updatedval;
}

void PrintSTLArray(const array<int,5> arr) {
    //arr[0] = 40;
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    array<int, 5> arr = {1, 2, 3, 4, 5};

    //arr[1] = 30;

    Update(arr, 1, 30);

    //for(int i = 0; i < 5; i++) {
    //    cout << arr[i] << " ";
    //}
    
    //cout << endl;

    PrintSTLArray(arr);
    
    return 0;
} */




// SORTING AN ARRAY

/* #include<iostream>
#include<array>
#include<algorithm>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    array<int, 5> arr = {10, 2, 30, 4, 50};

    //arr.begin();
    //arr.end();
    sort(arr.begin(), arr.end());

    //sort(arr, arr+n); // for classical array sort({begining address of the array(arr)}, {address after ending of the array(arr+n) })

    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    return 0;
}*/





// FILL AN ENTIRE ARRAY WITH A PARTICULAR VALUE

/* #include<iostream>
#include<array>
#include<algorithm>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    array<int, 10> filledarray;
    filledarray.fill(2);

    for(int num:filledarray){
        cout << num << " ";
    }

    //arr[i];
    //arr.at(i);
    //arr.front();
    //arr.back();

    // fill(arr.begin(), arr.end(), 10);

    //for(int i = 0; i < filledarray.size(); i++) {
    //    cout << filledarray[i] << " ";
    //}
    
    cout << endl;

    return 0;
} */




// VECTORS (USED ONLY AT THE END)(DOUBLES THE SIZE EACH TIME TO INSERT AN EXTRA ELEMENTS WHEN ALL THE INDEXES ARE ALREADY FILLED UP)

/* #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    vector<int> vec = {1, 2, 3, 4, 5};

    //int arr[] = {10, 20, 30, 40, 50};
    //vector<int> vec(arr, arr + 5);

    // vector<int> second(vec);

    // vector<int> vec(5,0);

    //vec.size();
    //vec.capacity();
    //vec.max_size();
    //vec.push_back(6);
    //vec.pop_back();
    //vec.erase(vec.begin() + 3);
    //vec.erase(vec.begin(), vec.begin() + 4);
    //vec.clear();
    //vec.insert(vec.begin() + 2, 10);
    //vec.insert(vec.begin() + 2, 3, 10);
    //vec.insert(vec.begin() + 2, vec.begin(), vec.begin() + 2);
    //vec.emplace(vec.begin() + 2, 10);
    //vec.emplace_back(10);
    //vec.emplace_back(2, 10);
    //vec.emplace_back(vec.begin(), vec.begin() + 2);
    //vec.swap(second);
    //vec.resize(4);
    //vec.resize(6, 10);
    //vec.shrink_to_fit();
    //vec.at(2);
    //vec.front();
    //vec.back();
    //vec.data();
    //vec.assign(5, 10);
    //vec.assign(vec.begin(), vec.begin() + 2);
    //vec.assign(arr, arr + 5);

    //sort(vec.begin(), vec.end());

    //for(int i = 0; i < vec.size(); i++) {
    //    cout << vec[i] << " ";
    //}
    
    //cout << endl;

    return 0;
} */




// DEQUE (USED BOTH AT FRONT AND AT THE END)(CAN DO ANY FUNCTION AT THE FRONT OR THE END)

/* #include<iostream>
#include<deque>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    //deque<int> first;
    //deque<int> second(4, 100);
    //deque<int> third(second.begin(), second.end());
    //deque<int> fourth(third);

    //int arr[] = {1, 2, 3, 4, 5};
    //int n = sizeof(arr)/sizeof (arr[0]);
    //deque<int> fifth(arr, arr + n);

    //deque<int> deq = {1, 2, 3, 4, 5};

    //deq.size();
    //deq.max_size();
    //deq.resize(10);
    //deq.resize(10, 5);
    //deq.push_back(6);
    //deq.push_front(0);
    //deq.pop_back();
    //deq.pop_front();
    //deq.erase(deq.begin() + 3);
    //deq.erase(deq.begin(), deq.begin() + 4);
    //deq.clear();
    //deq.at(2);
    //deq.front();
    //deq.back();
    //deq.insert(deq.begin() + 3, 10);
    //deq.insert(deq.begin() + 3, 4, 10);
    //deq.insert(deq.begin() + 3, deq.begin(), deq.begin() + 4);
    //deq.assign(5, 10);
    //deq.assign(deq.begin(), deq.begin() + 4);
    //deq.swap(deq2);
    //deq.emplace(deq.begin() + 3, 10);
    //deq.emplace_back(10);
    //deq.emplace_front(10);
    //deq.emplace_back(4, 10);
    //deq.emplace_front(4, 10);
    //deq.emplace_back(deq.begin(), deq.begin() + 4);
    //deq.emplace_front(deq.begin(), deq.begin() + 4);
    //deq.push_back(10);
    //deq.push_front(10);
    //deq.shrink_to_fit();
    //deq.resize(10);
    //deq.resize(10, 5);
    //deq.assign(5, 10);
    //deq.assign(deq.begin(), deq.begin() + 4);
    //deq.assign(arr, arr + n);
    //deq.assign(deq.begin(), deq.begin() + 4);

    //for(int i = 0; i < deq.size(); i++) {
    //    cout << deq[i] << " ";
    //}
    
    //cout << endl;

    return 0;
} */




// STACK (1ST IN LAST OUT & LAST IN FIRST OUT)

/* #include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    stack<string> libraries;

    libraries.push("Physics");
    libraries.push("Chemistry");
    libraries.push("Computer Science");
    libraries.push("Mathematics");

    //libraries.size();
    //libraries.empty();
    //libraries.top();
    //libraries.pop();


    //for(int i = 0; i < str.size(); i++) {
    //    libraries.push(str[i]);
    //}

    while(!libraries.empty()) {
        cout << libraries.top() << endl;
        libraries.pop();
    }
    
    return 0;
} */




// QUEUE (FIRST IN FIRST OUT)(LAST IN LAST OUT)

/* #include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    queue<string> basket;

    basket.push("Fruits");
    basket.push("Drinks");
    basket.push("Biscuits");

    //cout << basket.front() << endl;

    while(!basket.empty()) {
        cout << basket.front() << endl;
        basket.pop();
    }

    //basket.size();
    //basket.empty();
    //basket.front();
    //basket.back();
    //basket.pop();

    return 0;
} */




// PRIORITY QUEUE (SORTED QUEUE)(SORTED IN DESCENDING ORDER)

/* #include<iostream>
#include<queue>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    //priority_queue<int> candies;

    //candies.push(100);
    //candies.push(50);
    //candies.push(90);
    //candies.push(20);
    //candies.push(30);

    //cout << candies.top() << endl;

    //while(!candies.empty()) {
    //    cout << candies.top() << endl;
    //    candies.pop();
    //}

    // FOR SORTING IN ASSCENDING ORDER

    priority_queue<int, vector<int>, greater<int>> candies;

    candies.push(100);
    candies.push(50);
    candies.push(90);
    candies.push(20);
    candies.push(30);

    //cout << candies.top() << endl;

    while(!candies.empty()) {
        cout << candies.top() << endl;
        candies.pop();
    }

    //candies.size();
    //candies.empty();
    //candies.top();
    //candies.pop();

    return 0;
} */