#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int nr;
        cin >> nr;
        nums.push_back(nr);
    }

    sort(nums.begin(), nums.end());

    long long int nr_curent = nums[0];
    long long int rez = 0;
    for (int i = 0; i < n-1; i++) {
        nr_curent += nums[i+1];
        rez += nr_curent;
    }

    cout << rez << '\n';

    return 0;
}




















// #include<bits/stdc++.h>
// using namespace std;

// void printpriorityqueue(
//     priority_queue<int, vector<int>,
//     greater<int>> pq
// ) {
//     priority_queue<int,vector<int>,greater<int>> pq2=pq;
//     while(!pq.empty()) {
//         cout<<pq.top()<<"\n";
//         pq.pop();
//     }
// }

// int main() {
//     priority_queue<int,vector<int>,greater<int>> pq;
//     for(int i=1;i<=5;i++)
//         pq.push(i);
    
//     cout<<"The elements of the priority queue are:"<<endl;
//     printpriorityqueue(pq);
    
//     cout<<"The size of the priority queue: "<<pq.size()<<endl;
//     cout<<"The top element of the priority queue: "<<pq.top()<<endl;
//     cout<<"Pop the top element: "<<endl;
//     pq.pop();
//     printpriorityqueue(pq);
// }