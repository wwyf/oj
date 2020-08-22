// http://codeforces.com/problemset/problem/4/A
#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    if (num >= 4 && num % 2 == 0){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}