//
// Created by Turakulov Islombek on 26.09.2021.
//

#ifndef ACS_HW_1_UTILS_H
#define ACS_HW_1_UTILS_H

#include <string>
#include <cstdlib>

void initRand();

int randomInteger(int min, int max);

char *randomWord(int len);

char *copyElementFromString(std::string &str);

#endif //ACS_HW_1_UTILS_H
