/*
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen, Nguyen Hoang Minh
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Fall 2017
 *               This file implements functions used for database management
 * =========================================================================================
 */

#include "dbLib.h"

#include <time.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

using namespace std;

void    strPrintTime(char* des, time_t& t) {
    tm *pTime = gmtime(&t);
    strftime(des, 26, "%Y-%m-%d %H:%M:%S", pTime);
}

void loadNinjaDB(char* fName, L1List<NinjaInfo_t> &db) {
	// TODO: write code to load information from file into db
    ifstream  database(fName);
    NinjaInfo_t ninja;
    string line, a, b, c, d, e, f, g, h;
    getline(database,line);
    char id[10];
    while(!database.eof()){
        getline(database,a,','); 
        getline(database,b,',');  
        getline(database,c,',');  
        getline(database,d,',');  
        getline(database,e,',');  
        getline(database,f,',');  
        getline(database,g,',');  
        getline(database,h,',');  
        

        char time[20];
        strcpy(time, b.c_str());
        struct tm tm;
        strptime(time, "%d/%m/%Y %H:%M:%S", &tm);
        time_t t = mktime(&tm);  // t is now your desired time_t
        ninja.timestamp = t;


        char* ninjaTag;
        // strcpy(ninjaTag, c.c_str());
        int i;
        // while (strlen(ninjaTag) < 4){
        //     i=strlen(ninjaTag);
        //     ninjaTag[i] = ninjaTag[i-1];
        //     ninjaTag[0] = 0;
        // }
        
        strcpy(ninja.id, c.c_str());
        strcpy(id, "");
        if (strlen(ninja.id) == 1){
            strcat(id, "000");
        }
        else if (strlen(ninja.id) == 2){
            strcat(id, "00");
        }
        else if (strlen(ninja.id) == 3){
            strcat(id, "0");
        }
        strcat(id, ninja.id);
        strcpy(ninja.id, id);
        
        

        //cout << "+++" <<ninja.id << endl;

        double longt = stol(d);
        ninja.longitude = longt;

        

        double lat = stod(e);
        ninja.latitude = lat;

        db.push_back(ninja);
    }
    database.close();
    
    
}

bool parseNinjaInfo(char* pBuf, NinjaInfo_t& nInfo) {
    // TODO: write code to parse information from a string buffer, ignore if you don't use it
    return true;
}


void process(L1List<ninjaEvent_t>& eventList, L1List<NinjaInfo_t>& bList) {
    
    while (!eventList.isEmpty()) {
        if(!processEvent(eventList[0], bList)) cout << eventList[0].code << " is an invalid event\n";
        if (strcmp(eventList[0].code, "0") == 0){
            cout << "0:";
            for (int i=0; i<eventList.getSize() ;i++){
                cout << " " << eventList[i].code;
            }
            cout <<  endl;
        }
        eventList.removeHead();
    }
}

void printNinjaInfo(NinjaInfo_t& b) {
    printf("%s: (%0.5f, %0.5f), %s\n", b.id, b.longitude, b.latitude, ctime(&b.timestamp));
}

/// This function converts decimal degrees to radians
double deg2rad(double deg) {
    return (deg * pi / 180);
}

///  This function converts radians to decimal degrees
double rad2deg(double rad) {
    return (rad * 180 / pi);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}