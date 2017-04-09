// Text Suggestion.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include<fstream>
using namespace std;

int main()
{
	string term, line, prevLine;
	
	//get string input
	cin >> term;

	//open a file in read mode
	ifstream input("store.txt");

	//repeat till something is output
	if(input.is_open())
	{
		//read a line, store it in a string
		while ((input.eof() == false) && (getline(input, line)) && (term.compare(line)<=0))
		{
			int match = 0;
			//compare string to line
			for (; (match < term.length()) && (match < line.length()) && (term[match] == line[match]); ++match);
			
			//if all characters match, print line.
			if (match == term.length())
			{
				cout << endl << "Match: " << line;
			}
			else
			{
				break;
			}

			////if not all match, compare with previous line.
			//else if (match == line.length)
			//{
			//	if (line.length() > prevLine.length())
			//	{
			//		prevLine = line;
			//	}
			//}


			//		//if less are matched, print previous
			//		//if same are matched, go to the next one
			//		//if more are matched, go to the next one and update max matched counter
		}
	}
	//if end of file is reached, nothing was output. print "No suggestions."
	cout << endl << "No match" << endl;

	input.close();
	//WOW, FANTASTIC BABY.
    return 0;
}

