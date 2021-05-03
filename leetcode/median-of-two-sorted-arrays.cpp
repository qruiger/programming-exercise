class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int alen = a.size();
        int blen = b.size();
        int clen = alen + blen;
        vector<int> c;
        int k = 0, i = 0, j = 0, flag = 0;
        double median = 1.0;
        // if merged array size has reached (alen+blen)/2 + 1
        // then we don't need to merge the arrays further
        while (i < alen && j < blen) {
            if (a[i] <= b[j])
                c.push_back(a[i++]);
            else if (a[i] >= b[j])
                c.push_back(b[j++]);
            if ( (c.size() - 1) == ((clen - 1) / 2) + 1) {
                flag = 1;
                break;
            }
        }
        // if a or b array was exhausted above
        // then fill the unexhausted array's values directly into c
        if (!flag) {
            while (i < alen)
                c.push_back(a[i++]);
            while (j < blen)
                c.push_back(b[j++]);
        }
        clen--;
        if (clen % 2 == 0)
            median = c[clen / 2];
        else
            median = 1.0 * (c[clen / 2] + c[clen / 2 + 1]) / 2;
        return median;
    }
};