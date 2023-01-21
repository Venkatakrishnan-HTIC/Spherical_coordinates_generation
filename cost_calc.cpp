#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int main(int argc, char* argv) {
    double l2n;
    double rms=0;

    ifstream inputFile1,inputFile2,inputFile3; 

    inputFile1.open("incorrect.csv");
    inputFile2.open("delta.csv");
    inputFile3.open("norm.csv");
    
    string line1 = "";
    string line2 = "";
    string line3 = "";

    while (getline(inputFile1,line1) && getline(inputFile2,line2) && getline(inputFile3,line3)){
        double x_n;
        double y_n;
        double z_n;
        double delta_x;
        double delta_y;
        double delta_z;
        double l2norm;
        string tempString = "";

        stringstream inputString1(line1);
        stringstream inputString2(line2);
        stringstream inputString3(line3);

        getline(inputString1,tempString,',');
        x_n=atof(tempString.c_str());
        tempString = "";
        getline(inputString1,tempString,',');
        y_n=atof(tempString.c_str());
        tempString = "";
        getline(inputString1,tempString,',');
        z_n=atof(tempString.c_str());
        tempString = "";
        getline(inputString2,tempString,',');
        delta_x=atof(tempString.c_str());
        tempString = "";
        getline(inputString2,tempString,',');
        delta_y=atof(tempString.c_str());
        tempString = "";
        getline(inputString2,tempString,',');
        delta_z=atof(tempString.c_str());
        tempString = "";
        getline(inputString3,tempString,',');
        l2norm=atof(tempString.c_str());
        tempString = "";

        line1 = "";
        line2 = "";
        line3 = "";
        
        // l2n = sqrt(pow(delta_x,2) + pow(delta_x,2) + pow(delta_x,2));
        rms += pow(l2norm,2);
    }
    rms = rms/100;
    rms = sqrt(rms);
    cout<< rms;
}