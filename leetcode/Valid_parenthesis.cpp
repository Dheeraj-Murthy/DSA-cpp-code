#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int>stk;
        // let {} - 1
        // let () - 2
        // let [] - 3
        for (auto i:s)
        {
            if (i == '{') stk.push(1);
            else if (i == '(') stk.push(2);
            else if (i == '[') stk.push(3);

            if (i == '}') if (!stk.empty() && stk.top()==1) stk.pop(); else return false;
            if (i == ')') if (!stk.empty() && stk.top()==2) stk.pop(); else return false;
            if (i == ']') if (!stk.empty() && stk.top()==3) stk.pop(); else return false;
        }
        if (stk.empty())
            return true;
        return false;
    }
};