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
    regex code("(([0-4]|9|10|12|14)?|(5|6|7|8|11)+[[:digit:]]{2,4}|(13)+[[:digit:]]{16})");

    if (regex_match(event.code, code)) return true;
    else return false;
}

void printFirstNinjaTag(L1List<NinjaInfo_t>& nList){
    printf("%s\n", nList[0].id);
}

void printLastNinjaTag(L1List<NinjaInfo_t>& nList){
    printf("%s\n", nList[nList.getSize()-1].id);
}

int countNinja(L1List<NinjaInfo_t>& nList){
    int count;
    if (nList.isEmpty()){
        count = 0;
    }
    else {
        count = 1;
        for (int i=0; i<nList.getSize()-1; i++){
            if (strcmp(nList[i].id, nList[i+1].id) != 0 ) count++;
        }
    }
    return count;
}

char* biggestNinjaTag(L1List<NinjaInfo_t>& nList){
    char* result= nList[0].id;
    for (int i=0; i<nList.getSize()-1; i++){
        if (strcmp(nList[i+1].id, nList[i].id) >0 ) result = nList[i+1].id;
    }
    return result;
}

char* validNinjaTag(char* code){
    char* id = new char();
    id = code;
    if (strlen(id) == 1){
        strcat(id, "000");
    }
    else if (strlen(id) == 2){
        strcat(id, "00");
    }
    else if (strlen(id) == 3){
        strcat(id, "0");
    }
    return id;
}
char* getNinjaTag(char* code){
    char* tag = code;
    for (int i=0; i<strlen(tag); i++){
        tag[i] = tag[i+1];
    }
    return tag;
}
char* startTime(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList){
    char* ninjaTag = getNinjaTag(event.code);
    // cout << validNinjaTag(nList[0].id) << " " << ninjaTag;
    int i=0;
    while (i < nList.getSize()){
        if (strcmp(validNinjaTag(nList[i].id), ninjaTag) == 0){
            if (strcmp(nList[i].id, nList[i+1].id) == 0){
                if (distanceEarth(nList[i].latitude, nList[i].longitude, nList[i+1].latitude, nList[i+1].longitude)){
                    return ctime(&nList[i+1].timestamp);
                }
            }
        }
        i++;
    }
    strcpy(ninjaTag, "-1");
    return ninjaTag;
}
// char* endTime(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList){
//     char* ninjaTag = getNinjaTag(event.code);
//     // cout << validNinjaTag(nList[0].id) << " " << ninjaTag;
//     int i=0, j=0;
//     while (i < nList.getSize()-1){
//         if (strcmp(validNinjaTag(nList[i].id), ninjaTag) == 0 && strcmp(validNinjaTag(nList[i+1].id), ninjaTag) != 0){
//             while (strcmp(validNinjaTag(nList[i-j].id), ninjaTag) == 0){
//                 j++;
//             }
//             return ctime(&nList[i-j+1].timestamp);
//         }
//         i++;
//     }
//     strcpy(ninjaTag, "-1");
//     return ninjaTag;
// }

bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList) {
    if (checkValidEvent(event) == false) return false; 
    if (event.code[0] == '1'){
        cout << event.code << ": ";
        printFirstNinjaTag(nList);
    }
    else if (event.code[0] == '2'){
        cout << event.code << ": ";
        printLastNinjaTag(nList);
    }
    else if (event.code[0] == '3'){
        cout << event.code << ": ";
        cout << countNinja(nList) << endl;
    }
    else if (event.code[0] == '4'){
        cout << event.code << ": ";
        cout << biggestNinjaTag(nList) << endl;
    }
    else if (event.code[0] == '5'){
        cout << event.code << ": ";
        cout << startTime(event, nList) << endl;
    }
    // else if (event.code[0] == '6'){
    //     cout << event.code << ": ";
    //     cout << endTime(event, nList) << endl;
    // }
    return true;
}


