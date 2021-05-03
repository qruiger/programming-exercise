class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        map<char, int>::iterator it;
        int curr = 0, ans = 0, i = 0, n = s.length(), index;
        while (i < n) {
            it = m.find(s[i]);
            /* if a character has not been appeared before,
            store the character and it's index in map */
            // curr tells the substring length so far
            // ans stores only the longest substring so far
            if (it == m.end()) {
                curr++;
                m.insert(make_pair(s[i], i));
                ans = max(ans, curr);
                i++;
            }
            // if a character has appeared before it will be there in map
            /* we need to set i to index+1 where index is the original
            position of the current character*/
            else {
                index = m[s[i]];
                if (i != n - 1)  // if we are at last character, do nothing
                    i = index + 1;
                // reset curr and map to start counting for the next substring 
                curr = 0;
                m.clear();
            }
        }
        return ans;
    }
};