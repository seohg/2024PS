//https://www.acmicpc.net/problem/15659
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int N;
int arr[12];
int oper[4] = {0};
int order[12];
int minV = INT_MAX, maxV = INT_MIN;

int calculator() {
  int tmp[12] = {0};

  for (int i = 0; i < N; i++) {
    tmp[i] = arr[i];
  }
  
  for (int i = 0; i < N - 1; i++) {
    int tmpval;
    if (order[i] == 2) {
      tmpval = tmp[i] * tmp[i + 1];
      tmp[i] = tmpval;
      tmp[i+1] = tmpval;

      int k = i-1;
      while(k>=0){
        if(order[k] == 0 || order[k] == 1){
          break;
        }
        tmp[k] = tmpval;
        k--;
      }
    }
    if (order[i] == 3) {
      tmpval = tmp[i] / tmp[i + 1];
      tmp[i] = tmpval;
      tmp[i+1] = tmpval;

      int k = i-1;
      while(k>=0){
        if(order[k] == 0 || order[k] == 1){
          break;
        }
        tmp[k] = tmpval;
        k--;
      }
    }
    
  }

  int value = tmp[0];

  for (int i = 0; i < N; i++) {
    if (order[i] == 0) {
      value += tmp[i + 1];
    }
    if (order[i] == 1) {
      value -= tmp[i + 1];
    }
  }

  return value;
};

void rec_func(int k) {
  if (k == N - 1) {
    int value = calculator();
    maxV = max(maxV, value);
    minV = min(minV, value);
  } else {
    for (int i = 0; i < 4; i++) {
      if (oper[i] >= 1) {
        oper[i]--;
        order[k] = i;
        rec_func(k + 1);
        oper[i]++;
        order[k] = i;
      }
    }
  }
};

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < 4; i++) {
    cin >> oper[i];
  }

  rec_func(0);
  cout << maxV << endl;
  cout << minV << endl;

  return 0;
}