#include <iostream>
using namespace std;

/*easy solution
bool isMaxHeap(int input[],int n){
  for(int child=1;child<n;child++){
    int parent= (child-1)/2;
    if(input[parent]< input[child])
      return false;
  }

  return true;
}
*/


bool check(int input[], int parent_index, int n){
    if(parent_index*2+1 >= n)
        return true;

    int child_l= 2*parent_index+1;
    int child_r= 2*parent_index+2;
    if(input[child_l]> input[parent_index])
        return false;

    if(child_r < n){
      if(input[child_r]> input[parent_index])
        return false;
    }

    check(input, parent_index+1, n);

}

bool isMaxHeap(int input[], int n){

    check(input,0, n);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}
