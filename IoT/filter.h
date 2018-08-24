#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Filter
{
public:
    void Run(string path,string keyword, string mode);
    void ReadFile(string path);
    void GenerateFile(string input);
    void PreciseFilterWord(string keyword);
    void FilterWord(string keyword);
    void RemoveWord(string keyword);
    int NumOfRecord(){return _numOfRecord;};

private:
    string _path;
    vector<string> _buffer;
    vector<string> _filterBuffer;
    int _numOfRecord=0;
};
