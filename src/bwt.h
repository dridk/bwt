#ifndef BWT_H
#define BWT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Bwt
{

public:

    // Convert readable string to bwt
    string transform(const string& text);

    // Convert bwt to readable string
    string reverse(const string& text);


    protected:
    // Return the suffix array sorted by lexic
    vector<pair<string,int>> suffixArray(const string& text);

    // Return the bw sorted
    vector<int> rank(const string& txt);



};

#endif // BWT_H
