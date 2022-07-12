#include <iostream>
using namespace std;

#include<unordered_map>
#include<math.h>
int getPairsWithDifferenceK(int *a, int n, int k) {
	// Write your code here
  unordered_map<int,int> m;
  int count=0;
  for(int i=0;i<n;i++){
    m[a[i]]++;
  }
  for(int i=0;i<n;i++){
    int c=a[i]-k;
    int b=a[i]+k;
    int x=m[a[i]];

    if(k==0){
      count+=x*(x-1)/2;
      m[a[i]]=0;
    }
    count+=x*m[c]+x*m[b];
    m[a[i]]=0;
  }

  return count;

}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
