#include <bits/stdc++.h>
using namespace std;

int count(int n, int *ans){
  if(n<=1){
    ans[n]=0;
    return ans[n];
  }

  if(ans[n]!=-1){
    return ans[n];
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

  cout<<"n,a,b,c:"<<n<<" "<<a<<" "<<b<<" "<<c<<endl;
  int x= min(a,min(b,c))+1;
  ans[n]=x;
  return x;
}

int countStepsToOne(int n){
  int *ans= new int[n+1];

  for(int i=0;i<n+1;i++){
    ans[i]=-1;
  }

  int a= count(n, ans);
  for(int i=0;i<n+1;i++){
    cout<<ans[i]<<endl;
  }
  return a;
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
