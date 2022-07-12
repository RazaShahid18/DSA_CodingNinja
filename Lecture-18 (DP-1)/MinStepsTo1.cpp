#include <bits/stdc++.h>
using namespace std;

int countMinStepsToOne(int n){
  if(n==1){
    return 0;
  }
  int a= countMinStepsToOne(n-1);
  int b=INT_MAX;
  if(n%2==0){
    b= countMinStepsToOne(n/2);
  }
  int c= INT_MAX;
  if(n%3==0){
    c= countMinStepsToOne(n/3);
  }

  return min(a,min(b,c))+1;
}

int main(){
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}
