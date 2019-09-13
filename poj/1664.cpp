#include <iostream>
using namespace std;

int solve(int m, int n){
    if (n >= m){
        n = m;
    }
    if (n == 1){
        // 只有一个盆子，那只有一种放的方法
        return 1;
    }
    if (m <= 1){
        // 只有一个/或者没有苹果，也是只有一种放法
        // 没有苹果的话就是相当于每个盆子一个苹果
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += solve(m-i, i);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    while (n--){
        int M,N;
        cin >> M >> N;
        cout << solve(M, N) << endl; 
    }
    return 0;
}