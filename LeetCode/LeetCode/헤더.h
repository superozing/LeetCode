#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <algorithm>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};