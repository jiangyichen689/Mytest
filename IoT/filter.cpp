#include "filter.h"

void Filter::Run(string path,string keyword,string mode)
{
    ReadFile(path);

    switch (mode[1])
    {
        case 'f': FilterWord(keyword);break;
        case 'p': PreciseFilterWord(keyword); break;
        case 'r': RemoveWord(keyword); break;
        default : cout<<"Wrong parameters"<<endl; break;
    }

    GenerateFile(keyword);
}

void Filter::ReadFile(string path)
{
    _path=path;
    string line;
    ifstream myfile(_path);
    string tmp="";
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            if(line[0]=='=' && line[line.length()-3]=='=')
            {
                _buffer.push_back(tmp);
                tmp="";
            }
            tmp+=line+"\n";
        }
        _buffer.push_back(tmp);
        myfile.close();
    }
    else
        cout<<" path is not correct and can't open file"<<endl;
}

void Filter::GenerateFile(string input)
{
    if(!_filterBuffer.empty())
    {
        string path = "./result/" + input;
        ofstream myfile (path);
        if(myfile.is_open())
        {
            for(int i=0;i<_filterBuffer.size();i++)
            {
                string output=_filterBuffer[i];
                myfile<<output;
            }
            myfile.close();
        }
    }
}

void Filter::PreciseFilterWord(string keyword)
{
    transform(keyword.begin(),keyword.end(),keyword.begin(),::tolower);
    for(int i=0;i<_buffer.size();i++)
    {
        string tmp = _buffer[i];
        transform(tmp.begin(),tmp.end(),tmp.begin(), :: tolower);
        size_t found=tmp.find(keyword);
        while(found!=string::npos)
        {
            if(found+keyword.length()<tmp.length() && tmp[found+keyword.length()]==' ')
            {
                _filterBuffer.push_back(_buffer[i]);
                _numOfRecord++;
                break;
            }
            found+=found+keyword.length();
            found=tmp.find(keyword,found);
        }   
    }

}

void Filter::FilterWord(string keyword)
{
    transform(keyword.begin(),keyword.end(),keyword.begin(),::tolower);
    for(int i=0;i<_buffer.size();i++)
    {
        string tmp = _buffer[i];
        transform(tmp.begin(),tmp.end(),tmp.begin(), :: tolower);
        size_t found=tmp.find(keyword);
        if(found!=string::npos)
        {
            _filterBuffer.push_back(_buffer[i]);
        }
            
    }
    _numOfRecord=_filterBuffer.size();
}

void Filter::RemoveWord(string keyword)
{
    transform(keyword.begin(),keyword.end(),keyword.begin(),::tolower);
    for(int i=0;i<_buffer.size();i++)
    {
        string tmp = _buffer[i];
        if(_buffer[i]!="\n")
        {
            transform(tmp.begin(),tmp.end(),tmp.begin(), :: tolower);
            size_t found=tmp.find(keyword);
            if(found == string::npos)
            {
                _filterBuffer.push_back(_buffer[i]);
            } 
        }     
    }
    _numOfRecord=_filterBuffer.size();
}