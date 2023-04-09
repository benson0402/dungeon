// Some Small And Useful Function
#pragma once

#include <random>
#include <string>
#include <algorithm>

static std::mt19937 NumGen(time(0));

int RngNum(int l, int r);

std::string IntToString(int x);

int StringToInt(std::string str);