//https://www.acmicpc.net/problem/2580
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sudoku[9][9];
bool flag = false;
vector<pair<int, int>> v;

bool check(int x, int y){
  for(int i=0;i<9;i++){
    if(i!=x && sudoku[i][y] == sudoku[x][y]) return false;
    if(i!=y && sudoku[x][i] == sudoku[x][y]) return false;
  }

  for(int i=(x/3)*3;i<(x/3)*3+3;i++){
    for(int j=(y/3)*3;j<(y/3)*3+3;j++){
      if(i==x && j==y) continue;
      if(sudoku[i][j] == sudoku[x][y]) return false;
    }
  }
  
  return true;
}

void dfs(int cnt){
  if(cnt == v.size()){
    flag = true;
    return;
  }
  int x = v[cnt].first;
  int y = v[cnt].second;
  for(int i=1;i<=9;i++){
    sudoku[x][y] = i;
    if(check(x,y)){
      dfs(cnt+1);
    }
    if(flag) return;
  }
  sudoku[x][y] = 0;
  return;
}

int main(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin>>sudoku[i][j];
      if(sudoku[i][j] == 0){
        v.push_back(make_pair(i,j));
      }
    }
  }
  dfs(0);
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cout<<sudoku[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}