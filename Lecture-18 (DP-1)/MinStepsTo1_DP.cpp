#include <bits/stdc++.h>
using namespace std;

/*
int count(int n, int *ans){
  if(n==1){
    return 0;
  }

  if(ans[n]!=-1){
    return ans[n]+1;
  }
  int a= count(n-1,ans);
  int b=INT_MAX;
  if(n%2==0){
    b= count(n/2,ans);
  }
  int c= INT_MAX;
  if(n%3==0){
    c= count(n/3,ans);
  }

  ans[n]= min(a,min(b,c))+1;
  return ans[n];
}
*/

int countStepsToOne(int n){
  int *ans= new int[n+1];

  ans[0]=0;
  ans[1]=0;
  for(int i=2;i<=n;i++){
    int a= ans[i-1];
    int b=INT_MAX;
    if(i%2==0){
      b= ans[i/2];
    }
    int c= INT_MAX;
    if(i%3==0){
      c= ans[i/3];
    }

    ans[i]= min(a,min(b,c))+1;
  }
  return ans[n];
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
