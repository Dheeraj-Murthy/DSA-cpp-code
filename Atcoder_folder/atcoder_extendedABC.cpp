#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a; cin >> a;
    for (auto it = a.begin()+1; it < a.end(); it++){
        if ((*it - *(it-1)) < 0){
            cout << "No";
            return 0;
        }  
    }
    cout << "Yes";
}