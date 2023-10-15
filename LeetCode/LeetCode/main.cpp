#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

struct sLog
{
    string log;

    string source;
    bool isLetter;
};

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        map<string, sLog>   LetterLog;
        map<string, sLog>   DigitLog;
        sLog        insertLog;

        for (size_t i = 0; i < logs.size(); ++i)
        {
            
            insertLog.log.clear();
            insertLog.source.clear();

            // 1. 식별자와 로그 구분
            string sBuf = logs[i];

            insertLog.source = sBuf;

            for (size_t j = 0; j < sBuf.length() - 1; ++j)
            {
                if (sBuf[j] == ' ')
                {
                    for (size_t k = j + 1; k < sBuf.length() - 1; ++k)
                        insertLog.log += sBuf[k];
                    break;
                }
            }
            for (size_t j = 0; sBuf[j] != ' '; ++j)
                insertLog.log += sBuf[j];

            // 2. 로그가 글자 로그인지, 숫자 로그인지 구분
            if (48 <= insertLog.log[0] && insertLog.log[0] <= 57)
                DigitLog.insert(make_pair(insertLog.log, insertLog));
            else
                LetterLog.insert(make_pair(insertLog.log, insertLog));
        }

        logs.clear();

        for (map<string, sLog>::iterator it = LetterLog.begin(); it != LetterLog.end(); ++it)
            logs.push_back(it->second.source);
        for (map<string, sLog>::iterator it = DigitLog.begin(); it != DigitLog.end(); ++it)
            logs.push_back(it->second.source);

        return logs;
    }
};
