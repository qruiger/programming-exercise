#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int> res;
        int val1, val2, n = a.size();
        map<int, int> store;
        map<int, int>::iterator it;
        // store element as key and it's index as mapped value
        for (int i = 0; i < n; i++)
            store.insert(make_pair(a[i], i));
        //uncomment to check the map values
        /*for(it=store.begin();it!=store.end();it++)
            cout<<it->first<<" "<<it->second<<"\n";
        cout<<"\n";*/
        for (int i = 0; i < n; i++) {
            it = store.find(target - a[i]);
            // search for the second value and make sure it is at
            // a different index than the current index
            if (it != store.end() && it->second != i) {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, target, x;
        cin >> n >> target;
        vector<int> nums, res;
        for (int i = 0; i < n; i++) {
            cin >> x;
            nums.push_back(x);
        }
        Solution s;
        res = s.twoSum(nums, target);
        cout << res[0] << " " << res[1];
        cout << "\n";
    }
    return 0;
}