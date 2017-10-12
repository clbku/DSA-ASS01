/*
 * =========================================================================================
 * Name        : eventLib.cpp
 * Author      : Duc Dung Nguyen, Nguyen Hoang Minh
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Fall 2017
 *               This library contains functions used for event management
 * =========================================================================================
 */

#include "eventLib.h"


template <typename T>
std::string genericToString(const T& t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

/// NOTE: each event will be separated by spaces, or endline character
void loadEvents(char* fName, L1List<ninjaEvent_t> &eList) {
	ifstream  events(fName);
	string s1;
	ninjaEvent_t ninEvents;
	while (!events.eof()){
		string a;
		getline(events, s1);
		stringstream str(s1);
		while (str >> a){
			
			strcpy(ninEvents.code, genericToString(a).c_str());
			eList.push_back(ninEvents);
		}
	}
	
}
