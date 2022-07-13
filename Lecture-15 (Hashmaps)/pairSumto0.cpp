#include <iostream>
using namespace std;
#include<unordered_map>

int pairSum(int *a, int n) {
	// Write your code here
  // 1 2 -2 2 3

  unordered_map<int,int> elem;
  int count=0;
  for(int i=0;i<n;i++){
    elem[a[i]]+=1;
    if(a[i]!=0){
      if(elem.count(-a[i])>0){
        count+= elem[-a[i]];
        cout<<i<<"th iteration "<<count<<endl;
      }
    }
  }

  int z= elem[0];
  count+=z*(z-1)/2;


  return count;
}

void printPairSum(int *a, int n){
  unordered_map<int,int> elem;

  for(int i=0;i<n;i++){
    elem[a[i]]+=1;
    if(a[i]!=0){
      if(elem.count(-a[i])>0){
        cout<<a[i]<<" "<<-a[i]<<endl;
      }
    }
  }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n)<<endl;

    printPairSum(arr,n);

    delete[] arr;
}
