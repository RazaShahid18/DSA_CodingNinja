#include <iostream>
#include <vector>
using namespace std;

#include<queue>
int kthLargest(int input[], int n, int k){
  priority_queue<int> pq;

  //making a max PriorityQueue using the given elements
  for(int i=0;i<n;i++){
    pq.push(input[i]);
  }

  while(k>1){
    pq.pop();
    k--;
  }

  return pq.top();

}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}
