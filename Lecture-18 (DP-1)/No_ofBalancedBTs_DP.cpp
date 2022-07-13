#include<bits/stdc++.h>
using namespace std;

int balancedBTs(int n){
  int mod= (int)(pow(10,9))+7;
  int *arr= new int[n+1];
  arr[0]=1;
  arr[1]=1;

  for(int i=2;i<=n;i++){
    int a=arr[i-1];
    int b=arr[i-2];

    int x= (int)(((long)(a)*a)% mod);
    int y= (int)((2*(long)(a)*b)% mod);
    int ans= (x+y)%mod;

    arr[i]=ans;
  }
  return arr[n];
}

int main(){
  int n;
  cin>>n;
  cout<<balancedBTs(n)<<endl;
}
