#include<bits/stdc++.h>
#include<vector>
using namespace std;

#include<queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    for(int i=0;i<n;i++){
    	q.push(i);
    }

    priority_queue<int> pq;
    for(int i=0;i<n;i++){
      pq.push(arr[i]);
    }

    int time=0;
    while(!q.empty()){
      if(arr[q.front()]== pq.top()){
        if(q.front()==k){
          time++;
          break;
        }
        pq.pop();
        time++;
        q.pop();
      }
      else{
        int x= q.front();
      	q.pop();
        q.push(x);
      }
    }

    return time;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}
