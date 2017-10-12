/*
 * =========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
 * =========================================================================================
 */
#include "eventLib.h"
#include <regex>
#include "dbLib.h"

bool checkValidEvent(ninjaEvent_t event){
    regex code("(([0-4]|9|10|12|14)?|(5|6|7|8|11)+[[:digit:]]{4}|(13)+[[:digit:]]{16})");
    if (regex_match(event.code, code)) return true;
    else return false;
}

void printFirstNinjaTag(L1List<NinjaInfo_t>& nList){
    printf("%s\n", nList[0].id);
}

bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList) {
    if (strcmp(event.code, "1") == 0){
        printFirstNinjaTag(nList);
    }
    return checkValidEvent(event);
}


