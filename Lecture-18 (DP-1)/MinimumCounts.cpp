#include <bits/stdc++.h>
using namespace std;

//Brute force
/*
int minCount(int n){
	//Write your code here
    if(n==1||n==0){
        return n;
    }

    int i=1;
    int mn=INT_MAX;
    while(i*i<=n){
        int a=1+minCount(n-(i*i));
        mn=min(a,mn);
        i++;
    }
    return mn;
}*/


//Memoisation
/*
int help(int n, int* arr){
  if(n==0 || n==1){
    return n;
  }
  int s=INT_MAX;
  int a=sqrt(n);
  if(a*a==n){
    return 1;
  }

  for(int i=1;i<=a;i++){
    int x;
    if(arr[n-i*i]!=-1){
      x=arr[n-i*i];
    }
    else{
      x=help(n-i*i,arr);
      arr[n-i*i]=x;
    }
      int j=x>s?s:x;
      s=j;
  }
  return s+1;
}

  int minCount(int n){
    int * ans= new int[n+1];
    for(int i=0;i<=n;i++){
      ans[i]=-1;
    }

    return help(n,ans);
  }
*/

//DP

int minCount(int n){
  int *a= new int[n+1];

  a[0]=0;
  a[1]=1;

  for(int i=2;i<=n;i++){
    a[i]=INT_MAX;

    for(int j=1;i-(j*j)>=0;j++){
      a[i]= min(a[i], a[i-(j*j)]);
    }
    a[i]++;
  }
  return a[n];

}


int main(){
	int n;
	cin >> n;
  cout << minCount(n);
}
