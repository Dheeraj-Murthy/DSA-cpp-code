#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n; cin >> n;
        int less;
        int greater;
        vector<int> notEqual;
        for (int j = 0; j < n; j++)
        {
            int a, x;
            cin >> a >> x;
            if ( (a == 1) && (x < greater))
                greater = x;
            else if ( (a == 2) && (x > less) )
                less = x;
            else if (a==3)
                notEqual.push_back(x);
        }
        for (int it = less; it <= greater; it++){
            if (it)
        }
    }
}