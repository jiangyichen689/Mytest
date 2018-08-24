#include "filter.h"
#include <string>

using namespace std;
int main(int argc, char** argv)
{
	string file;
	string mode;
	string keyword;
	Filter filter;

	for(int i=0;i<argc;i++)
	{
		if(i==1)
			mode= argv[i];
		if(i==2)
			file = argv[i];
		if(i==3)
			keyword = argv[i];
	}
	
	filter.Run(file,keyword, mode);
	cout<< "Total record is: "<< filter.NumOfRecord()<<endl;
	return 0;
}
