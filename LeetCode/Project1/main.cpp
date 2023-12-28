#include "헤더.h"
bool 누가클까용(int& _a, int& _b)
{
    string a, b;
    a = to_string(_a);
    b = to_string(_b);

    string aSum = (a + b);
    string bSum = (b + a);
    //return aSum > bSum;

    if (aSum <= bSum)
        return false;
    else
        return true;

    //return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        if (nums.size() == 1)
            return to_string(nums[0]);

        sort(nums.begin(), nums.end(), 누가클까용);
        if (nums[0] == 0)
        {
            return string{ "0" };
        }
        string returnStr;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            returnStr += to_string(nums[i]);
        }

        return returnStr;
    }
};

int main()
{
    Solution s;
    vector<int> v{ 0,0,0,0,0,0,0,0,0,0,0,0,0
        ,0,0,0,0,0,0,0,0,0,0,0,0,0
        ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    s.largestNumber(v);

    return 0;
}