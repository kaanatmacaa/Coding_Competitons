/*
Google Hash Code 21 Qualifications //First coding competiton

Team members: 
    Kaan Atmaca 
    Mert Ture
    Kerem Kor
    Mizbah Celik

Points: 
    A - An example 2,002 points
    B - By the ocean 4,565,642 points
    C - Checkmate 1,231,878 points
    D - Daily commute 969,685 points
    E - Etoile 661,797 points
    F - Forever jammed 455,737 points
    Total point: 7,886,741 points

Ranking: 
    World: 4152
    Region(Turkey): 103
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <sstream>
#include <set>
#include <map>
#define N 10000

using namespace std;


struct street {
    string name;
    int beg, end, len, count;
};

struct car {
    int len2;
    vector<street> streets;
};

street findStreet(string name, vector<street> streets);
void fileRead(string fileName, vector<street>& st, vector<car>& cr, int& inter);


void fileRead(string fileName, vector<street>& st, vector<car>& cr, int& inter) {
    int seconds, intersections, streetNum, carNum, points;
    string line;
    ifstream f;
    f.open(fileName.c_str());
    getline(f, line);
    istringstream strinput(line);
    strinput >> seconds >> intersections >> streetNum >> carNum >> points;
    inter = intersections;
    for (int i = 0; i < streetNum; i++) {
        getline(f, line);
        istringstream strinput(line);
        street s;
        string name;
        int beg, end, len;
        strinput >> beg >> end >> name >> len;
        s.beg = beg;
        s.end = end;
        s.name = name;
        s.len = len;
        st.push_back(s);
    }

    for (int i = 0; i < carNum; i++) {
        getline(f, line);
        istringstream strinput(line);
        car c;
        int len2 = 0;
        vector<street> streets;

        strinput >> len2;
        string streetName;
        for (int i = 0; i < len2; i++) {
            strinput >> streetName;
            streets.push_back(findStreet(streetName, st));
        }
        c.len2 = len2;
        c.streets = streets;
        cr.push_back(c);
    }

}

street findStreet(string name, vector<street> streets)
{
    street temp;
    for (int i = 0; i < streets.size(); i++) {
        street current = streets[i];
        if (current.name == name) {
            return current;
        }
    }
    return temp;
}

int main() {
    int seconds, intersections, streets, cars, points;
    vector<street> s;
    vector<car> c;
    vector<string> cur;
    string fileName;
    cin >> fileName; 
    int intersection;
    fileRead(fileName, s, c, intersection);
    ofstream of;
    of.open("aout.txt");
    of << intersection << endl;
    for (int i = 0; i < intersection; i++)
    {
        cur.clear();
        cur.resize(0);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j].end == i)
            {
                cur.push_back(s[j].name);
            }

        }
        of << i << endl;
        of << cur.size() << endl;
        for (int i = 0; i < cur.size(); i++)
        {
            of << cur[i] << " " << 1 << endl;
        }
    }
    return 0;
}