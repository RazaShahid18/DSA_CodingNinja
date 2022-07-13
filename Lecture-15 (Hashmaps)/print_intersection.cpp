#include <iostream>
using namespace std;

#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
  // Write your code here
  unordered_map<int,int> elem;
  for(int i=0;i<n;i++){
    elem[arr1[i]]+=1;
  }

  for(int i=0;i<m;i++){
    if(elem[arr2[i]] >0){
      cout<<arr2[i]<<endl;
      elem[arr2[i]]-=1;
    }
  }

}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
