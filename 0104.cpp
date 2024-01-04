// https://www.acmicpc.net/problem/9663

#include <iostream>
using namespace std;

int N, cnt = 0;
int arr[15] = {0};

void dfs(int row){
  if(row == N+1){
    cnt++;
    return;
  }
  for(int i=1;i<=N;i++){
    bool flag = true;
    for(int j=1;j<row;j++){
      if(arr[row-j]==i||arr[row-j]==i-j||arr[row-j]==i+j){
        flag = false;
      }
    }
    if(flag){
      arr[row] = i; 
      dfs(row+1);
    }
  }
}
int main(){
  cin>>N;
  for(int i=1;i<=N;i++){
    arr[1] = i;
    dfs(2);
  }
  cout<<cnt;
}