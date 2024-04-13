#include<iostream>
using namespace std;

int main()
{
    double r; cin >> r;
    long long int x = r;
    long long int y = 0;
    long long int ans = 0;
    while (x > 0 && y < r)
    {
        if (x*x + y*y > r*r) x--;
        else {
            ans += x;   y++;
        }
    }
    ans *= 4;
    ans ++;
    cout << ans;
}