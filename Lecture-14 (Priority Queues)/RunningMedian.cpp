//6 2 1 3 7 5

#include<bits/stdc++.h>
using namespace std;

#include<queue>
void findMedian(int *a, int n){
    // Write your code here

    //TLE code
    /*priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
        vector<int> v;
        while(!pq.empty()){
          v.push_back(pq.top());
          pq.pop();
        }
        if(v.size()%2==0){
            int med= (v[v.size()/2]+v[v.size()/2 -1])/2;
            cout<<med<<" ";
        }
        else{
          cout<<v[v.size()/2]<<" ";
        }

        for(int j=v.size()-1;j>=0;j--){
          pq.push(v[j]);
        }
    }
    cout<<endl;
    return;*/


    //maitaining two priority queues eg
	// 1 2 3 | 4 5 6  so first one as maxheap and second one as minheap; median = max(first half)+ min(second half) /2
   	priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;


    for(int i=0;i<n;i++){

        //first element goes into the max heap
    	if(max.size()==0){
        	max.push(a[i]);
      }

        //if maxheap is not empty; if the next coming element is smaller than max of maxheap we push in it else in minheap
      else if(a[i]<max.top()){
        max.push(a[i]);

        //if size difference of the two heaps is greater than 1 we will try to maintain size diff of 1 or less
        if(abs(max.size()-min.size()) >1){
          min.push(max.top());
          max.pop();
        }
      }

      else if(a[i]> max.top()){
        min.push(a[i]);

        if(abs(max.size()-min.size()) >1){
          max.push(min.top());
          min.pop();
        }
      }

    //if both heaps of equal size then median will be average of the top most element of each heap
      if(max.size()==min.size()){
        int median= (max.top()+min.top())/2;
        cout<<median<<" ";
      }
    //if size not equal then median will be the the topmost element of heap with larger size
      else{
        if(max.size()>min.size())
          cout<<max.top()<<" ";
        else
          cout<<min.top()<<" ";
      }
    }

    return;




    /*for(int i=0;i<n;i++){
        pq.push(a[i]);
        vector<int> v;
        while(!pq.empty()){
          v.push_back(pq.top());
          pq.pop();
        }
        if(v.size()%2==0){
            int med= (v[v.size()/2]+v[v.size()/2 -1])/2;
            cout<<med<<" ";
        }
        else{
          cout<<v[v.size()/2]<<" ";
        }

        for(int j=v.size()-1;j>=0;j--){
          pq.push(v[j]);
        }
    }
    cout<<endl;
    */
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
