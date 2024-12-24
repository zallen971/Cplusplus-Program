#pragma once
#ifndef CLOCKFUNCTIONS_H
#define CLOCKFUNCTIONS_H

#include <iostream>
# include <iomanip>
#include<ctime>
using namespace std;

// function to display the 12 and 24 hour clocks
void displayClocks(int hour12, int minute, int second, int hour24);

// function to display the user choices menu
void displayMenu();

// function to add the time to both clocks
void addTime(int& hour12, int& hour24, int& minute, int& second, int choice);

#endif // CLOCKFUNCTIONS_H