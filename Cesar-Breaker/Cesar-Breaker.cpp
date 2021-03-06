// Cesar-Breaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

string get_content_from_file(string input);

int main(int argc, char * argv[])
{
	string path;
	string content;
	if (argc > 1)
	{
		path = argv[1];
		cout << "More than one arg" << endl;
		content = get_content_from_file(argv[1]);
	}
	string derp;
	getline(cin, derp);
    return 0;
}

string get_content_from_file(string input)
{
	string content;
	string line;
	ifstream input_file(input);
	if (input_file.is_open())
	{
		while (getline(input_file, line))
		{
			content += line;
		}
		input_file.close();
	}
	return content;
}
