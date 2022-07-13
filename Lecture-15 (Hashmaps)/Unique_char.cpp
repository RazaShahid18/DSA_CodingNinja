#include <iostream>
#include <string>
using namespace std;

#include<unordered_map>
#include<string>
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,int> m;
    string ans="";
    for(int i=0;i<str.length();i++){
        m[str[i]]=m[str[i]]+1;

    }
    unordered_map<char,int> :: iterator it= m.begin();
    while(it!=m.end()){
      ans+=it->first;
      it++;
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
