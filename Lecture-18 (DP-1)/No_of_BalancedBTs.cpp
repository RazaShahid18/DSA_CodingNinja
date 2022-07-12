#include<bits/stdc++.h>
using namespace std;


//Brute Force
/*
int balancedBTs(int n){
  if(n==1 || n==0){
    return 1;
  }
  int mod= (int) (pow(10,9))+7;
  int a=balancedBTs(n-1);
  int b=balancedBTs(n-2);

  int x= (int)(((long)(a)*a)% mod);
  int y= (int)((2*(long)(a)*b)% mod);
  int ans= (x+y)%mod;

  return ans;
}
*/

//Memoisation
/*
int help(int n, int* arr){
  int mod= (int) (pow(10,9))+7;
  if(n<=1){
    return 1;
  }

  if(arr[n]!=-1){
    return arr[n];
  }

  int a= help(n-1,arr);
  int b=help(n-2,arr);

  int x= (int)(((long)(a)*a)% mod);
  int y= (int)((2*(long)(a)*b)% mod);
  int ans= (x+y)%mod;

  arr[n]=ans;
  return arr[n];

}

int balancedBTs(int n){
  int *ans= new int [n+1];
  for(int i=0;i<n+1;i++){
    ans[i]=-1;
  }

  return help(n, ans);
}
*/

//DP

int balancedBTs(int n){
  int mod= (int)(pow(10,9))+7;
  int *arr= new int[n+1];ww
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


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
