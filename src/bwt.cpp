#include "bwt.h"

string Bwt::transform(const string &text)
{
    string source = text;
    string result ;
    source.append("$");

    vector<pair<string,int>> sa = suffixArray(source);

    for (int i=0; i<sa.size(); ++i)
    {
        int index = sa[i].second;
        if (index == 0)
            result+="$";
        else
            result += source.at(index-1);
    }

    return result;
}
//===================================================
string Bwt::reverse(const string &text)
{
    string firstCol = text;
    string lastCol  = text;
    sort(firstCol.begin(), firstCol.end());

    auto lastRank  = rank(lastCol);
    auto firstRank = rank(firstCol);

    string result;
    int index = 0;
    int rank  = 0;

    while (result.size() < text.size()-1)
    {
        char letter = lastCol[index];
        result      = letter + result;
        rank        = lastRank[index];

//        cout<<index<<endl;
//        cout<<letter<<endl;
//        cout<<rank<<endl;
//        cout<<"===="<<endl;

        for (int i=0; i < firstCol.size(); ++i)
        {
            if (( firstCol.at(i) == letter) && (firstRank[i] == rank)){
                index = i;
                break;
            }
        }
    }
    return result;
}
//===================================================

vector<pair<string,int>> Bwt::suffixArray(const string &text)
{
    vector<pair<string,int>> items;

    for (int i=0; i<text.size(); ++i)
    {
        string suffix = text.substr(i, text.size()-i);
        items.push_back(make_pair(suffix,i));

    }

    sort(items.begin(), items.end());
    return items;

}
//===================================================
vector<int> Bwt::rank(const string &txt)
{
    vector<int> result;
    map<char,int> dic;

    for (auto c : txt)
    {
        if (dic.count(c) !=1)
            dic[c] = 0 ;
        else
            dic[c] ++;

        result.push_back(dic[c]);
    }
    return result;
}
//===================================================


