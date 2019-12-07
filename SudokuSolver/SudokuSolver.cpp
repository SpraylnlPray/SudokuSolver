#include "pch.h"
#include "Field.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool solve(Field* field);

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
	cout << "Input: " << endl;
	field->showData();
	
	if (solve(field))
	{
		cout << "Solution:" << endl;
		field->showData();
	}
	else
		cout << "No solution possible" << endl;
}

bool solve(Field* field)
{
	const int gridSize = 9;

	SudokuEntry* emptyCell = field->getUnassignedCell();
	if (!emptyCell)
		return true;

	for (short i = 1; i <= gridSize; i++)
	{
		if (!emptyCell->block->containsValue(i) && !emptyCell->row->containsValue(i) && !emptyCell->col->containsValue(i))
		{
			emptyCell->value = i;
			if (solve(field))
				return true;

			emptyCell->value = 0;
		}
	}

	return false;

}
