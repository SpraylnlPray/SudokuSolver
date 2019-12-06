#include "pch.h"
#include "Field.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string input;

	ifstream reader("input.txt");
	if (reader.is_open())
	{
		getline(reader, input);
		reader.close();
	}
	else
		cout << "Error when opening file" << endl;

	Field* field = new Field(input);
}
