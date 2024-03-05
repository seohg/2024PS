#include <string>
#include <vector>

using namespace std;
int answer = 0;
int ch[201]={0};
void dfs(int n, vector<vector<int>> computers, int idx){
    ch[idx] = 1;
    for(int i=0;i<n;i++){
        if(ch[i]==0 && computers[idx][i]==1){
            dfs(n,computers,i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<n;i++){
        if(ch[i]==0){
            dfs(n, computers, i);
            answer++;
        }
    }
    
    return answer;
}