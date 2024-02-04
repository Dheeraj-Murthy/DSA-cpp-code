#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pow(int a[], int start, int end){
    int ans = 0;
    for (int i = start+1; i <= end; i++) {
        ans+= abs(a[i]-a[i-1]);
    }
    return ans;
}

int main(){
    int cases; cin >> cases;
    for (int ques=0; ques<cases; ques++)
    {
        int v,g; cin >> v >> g;
        int arr[v];
        vector<pair<int,int>> diff;
        
        for (int i=0; i<v; i++) 
        {
            cin >> arr[i];
            if (i==0) continue;
            diff.push_back( {abs(arr[i]-arr[i-1]), i-1} );
        }
        
        sort(diff.begin(),diff.end());
        cout<< "the array of differences ";
        for (auto it:diff) cout << it.first << "," <<  it.second << "  "; cout << endl;
        
        int br[g-1];
        for (int count=0; count < g-1; count++)
            br[count] = diff[v-1-count].second;
        
        sort(br, br+g-2);
        cout<< "the breakpoints ";
        for (int it: br) cout << it << " "; cout << endl;
        
        int ans=0;
        int prev=0;
        cout<< "the sum-point pairs ";
        for (int it:br){
            int temp = pow(arr, prev, it);
            ans += temp;
            cout << ' '<< temp << " : " << prev << "->"<<it;
            prev = it+1;
            
        }
        int temp = pow(arr, prev, sizeof(arr)/sizeof(int)-1);
        cout << " " << temp<< ':' << prev <<  "->end" << endl;
        for (int it:arr) cout << it << ' '; cout << endl;
        ans+= temp;
        
        cout<<"the ans :" << ans << endl;

    }
}