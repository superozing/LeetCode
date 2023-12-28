#include "Çì´õ.h"

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length())
            return false;

        vector<int> vec;
        vec.resize(25);

        for (int i = 0; i < s.length(); ++i)
        {
            vec[s[i] - 'a'] += 1;
            vec[t[i] - 'a'] -= 1;
        }

        for (auto& iter : vec)
        {
            if (iter) return false;
        }

        return true;

    }
};