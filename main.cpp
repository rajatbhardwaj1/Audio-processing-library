#include<iostream>
#include <cblas.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <algorithm>
#include "audiolib.h"
using namespace std;
//function to get the name of the sound corresponding to the label
string labeltotext(int i) {
    if (i == 0) {
        return  "silence";
    }
    else if (i == 1) {
        return  "unknown";
    }
    else if (i == 2) {
        return  "yes";
    }
    else if (i == 3) {
        return  "no";
    }
    else if (i == 4) {
        return  "up";
    }
    else if (i == 5) {
        return  "down";
    }
    else if (i == 6) {
        return  "left";
    }
    else if (i == 7) {
        return  "right";
    }
    else if (i == 8) {
        return  "on";
    }
    else if (i == 9) {
        return  "off";
    }
    else if (i == 10) {
        return  "stop";
    }
    else {
        return  "go";
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cerr << "Wrong number of commands entered!";
        return 0;
    }
    const char* inp = argv[1];
    string op = argv[2];


    pred_t pr[3];

    libaudioAPI(inp, pr);//applying the main function tof the library 

    string first, second, third;

    first = labeltotext(pr[0].label); 
    second = labeltotext(pr[1].label);
    third = labeltotext(pr[2].label);

    ofstream outputfile;

    outputfile.open(op, ios_base::app);

    outputfile << inp << " " << first << " " << second << " " << third << " " << pr[0].prob << " " << pr[1].prob<<" " << pr[2].prob << endl;

    return 0;
}
