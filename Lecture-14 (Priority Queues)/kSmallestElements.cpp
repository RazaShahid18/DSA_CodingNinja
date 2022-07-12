#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#include<queue>
#include<vector>

vector<int> kSmallest(int *input, int n, int k) {
	// Write your code here

    //making a max priority queue to store the first k elements which will act as the minimum k elements
	priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    //checking if the rest n-k elements should be part of the priority queue i.e.
    //any of the element of the pq is greater than the next element of the array
    for(int i=k;i<n;i++){
        if(input[i]<pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }

    //after full iteration of the input array, our pq now conatins the smallest k elements
    //so we store those min k elements in an vector and return it
    vector<int> ans;
    while(!pq.empty()){
      ans.push_back(pq.top());
      pq.pop();
    }

    return ans;
}

//main code
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}
