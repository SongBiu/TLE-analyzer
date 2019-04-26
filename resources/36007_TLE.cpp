#include <stdio.h>
#include <limits.h>

int main() {
    int MAX = INT_MAX; 
    int num = 0, ptr = 0; 
    while (1) {
        scanf("%d", &num);
        if (num == 0) break; 
        bool flag = false; 
        for (int modNum = num+1; modNum < INT_MAX; ++ modNum) {
            if (flag) break; 
            ptr = 0; 
            int totalNum = 2*num; 
            while (1) {
                ptr = ptr + modNum - 1; 
                ptr = ptr % totalNum; 
                //printf ("Killed #%d\n", ptr); 
                if (ptr < num) {
                    break;  
                }
                totalNum --; 
                if (totalNum == num) { 
                    flag = true; 
                    printf("%d\n", modNum);
                    break; 
                }
            }
        }
    }
    return 0; 
}