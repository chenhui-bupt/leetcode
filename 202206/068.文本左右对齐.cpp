class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        string s = "";
        int num = 0;
        int len = 0;
        int space = 0;
        for (int i = 0; i < n; ++i) {
            if (len + num + words[i].size() <= maxWidth) {
                ++num;
                len += words[i].size();
            } else {
                space = maxWidth - len;
                for (int j = i - num; j < i; ++j) {
                    s += words[j];
                    if (num == 1) {
                        s += string(space, ' ');
                    } else if (space % (num - 1) == 0) {
                        s += string(space / (num - 1), ' ');
                        space -= (space / (num - 1));
                    } else {
                        s += string(1 + space / (num - 1), ' ');
                        space -= (1 + space / (num - 1));
                    }
                    --num;
                }

                res.push_back(s);
                s = "";
                num = 0;
                len = 0;
                --i;
            }
        }

        s = "";
        for (int j = n - num; j < n; ++j) {
            if (s.size() == 0) {
                s += words[j];
            } else {
                s += " " + words[j];
            }
            --num;
        }
        if (s.size() > 0) {
            s += string(maxWidth - s.size(), ' ');
            res.push_back(s);
        }
        return res;
    }
};