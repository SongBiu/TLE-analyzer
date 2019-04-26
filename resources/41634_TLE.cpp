#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n){
        n *= 2;
        if(!n)
            break;
        int j = n / 2;
        while(true){
            int temp = 0; 
            bool flag = 0;
            for(int i = 0; i < n / 2; i++){
                temp = ((j + temp - 1 + n - i)) % (n - i);
                if(temp < n / 2){
                    flag = 1;
                    break;
                }
        }
        if(flag == 0)
            break;
        else
            ++j;
        }
        cout << j << endl;
    }
    return 0;
}