#include <iostream>
#include <vector>
#include<climits>
using namespace std;

#include<unordered_map>
#include<vector>

vector<int> longestConsecutiveIncreasingSequence(int *a, int n) {
    // Your Code goes here
    unordered_map<int,bool> m;
    vector<int> v;
    int start=INT_MIN;
    int end=INT_MAX;
    int maxLen=0;

    for(int i=0;i<n;i++){
      m[a[i]]=true;
    }
    for(int i=0;i<n;i++){
      int start1=a[i];
      int end1=a[i];
      int len=1;

      int j=0;
      while(j!=1){

        if(m[start1-1]!=true && m[end+1]!=true){
          j=1;
        }

        if(m[start1-1]==true){
          len++;
          start1--;
          m[start1]=false;
        }

        if(m[end1+1]==true){
          len++;
          end1++;
          m[end1]=false;
        }

      }

      if(maxLen<len){
        start=start1;
        end=end1;
        maxLen=len;
      }
    }

    v.push_back(start);
    v.push_back(end);
    return v;

}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
