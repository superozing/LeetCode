#include "Çì´õ.h"

class Solution
{
public:
    // ( )
    // { }
    // [ ]
    bool isValid(string s) 
    {
        char arr[3] = {};
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            for (int i = 0; i < s.length(); i++) 
            {
                switch (s[i]) 
                {
                case '(':
                    arr[count++] = '(';
                    break;
                case '{':
                    arr[count++] = '{';
                    break;
                case '[':
                    arr[count++] = '[';
                    break;
                case ')':
                    if (arr[count - 1] == '(')
                        arr[--count] = 0;
                    else return false;
                    break;
                case '}':
                    if (arr[count - 1] == '{')
                        arr[--count] = 0;
                    else return false;
                    break;
                case ']':
                    if (arr[count - 1] == '[')
                        arr[--count] = 0;
                    else return false;
                    break;
                }
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            if (arr[i] != 0)
                return false;
        }
        return true;
    }
};