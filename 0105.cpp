// https://www.acmicpc.net/problem/9095
#include <iostream>
using namespace std;

int main(){
  int T, N;
  int arr[11];
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  cin>>T;
  for(int i=4;i<=10;i++){
    arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
  }
  while(T--){
    cin>>N;
    cout<<arr[N]<<"\n";
  }
  return 0;
}