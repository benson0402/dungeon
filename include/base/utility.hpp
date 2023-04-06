// Some Small And Useful Function
#pragma once

#include <random>
#include <string>
#include <algorithm>

static std::mt19937 NumGen(time(0));

inline int RngNum(int l, int r) {
    int tmp = NumGen() % (r - l + 1);
    return l + tmp;
}

inline std::string IntToString(int x) {
    bool sign = 0;
    std::string ret;
    if(x < 0) {
        sign = 1;
        x = -x;
    }
    else if(x == 0) {
        return "0";
    }
    while(x != 0) {
        ret.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    if(sign) {
        ret = "-" + ret;
    }
    return ret;
}

inline int StringToInt(std::string str) {
    int ret = 0; 
    bool sign = 0;
    for(auto& x : str) {
        if(x == '-') {
            sign = 1;
        }
        else {
            ret *= 10;
            ret += x - '0';
        }
    }
    if(sign) {
        ret *= -1;
    }
    return ret;
}