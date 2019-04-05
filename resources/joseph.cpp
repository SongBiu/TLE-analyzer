//
// Created by lisong on 2019-04-01.
//
#include <stdio.h>
#include <string>
using namespace std;

int joseph(int n)
{
    int i;
    int midval = 0;

    for (i = 1; 1; i++)
    {
        int count = n;
        midval = 0;
        while (count > 0)
        {
            midval = (midval + i) % (n + count);
            if(midval < n)
                break;
            count--;
        }
        if (count != 0)
        {
            continue;
        }
        return i + 1;
    }
}

int main(void)
{
    int n;
    string line = "23333";
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        printf("%d\n", joseph(n));
    }
    printf("%s\n", line.c_str());
    return 0;
}

