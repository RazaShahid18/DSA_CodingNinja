#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>

int highestFrequency(int a[], int n) {
	// Write your code here
  unordered_map<int,int> freq;
  for(int i=0;i<n;i++){
    if(freq.count(a[i])==0){
      freq[a[i]]=1;
      continue;
    }
    freq[a[i]]++;
  }
  int max=0;
  int ans=-1;
  for(int i=n-1;i>=0;i--){
    if(freq[a[i]]>=max){
    	max=freq[a[i]];
      ans=a[i];
    }
  }

  return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
