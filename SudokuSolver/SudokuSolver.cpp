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
	try
	{
		ifstream reader("input.txt");
		if (reader.is_open())
		{
			getline(reader, input);
			reader.close();
		}
	}
	catch (exception& ex)
	{
		cout << "Error when opening the input file." << endl;
	}
	
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

	SudokuEntry* emptyCell = field->getUnassignedCell(); // check if the field has an empty cell
	if (!emptyCell)
		return true;

	for (short i = 1; i <= gridSize; i++) // go from 1 to 9
	{
		if (!emptyCell->block->containsValue(i) && !emptyCell->row->containsValue(i) && !emptyCell->col->containsValue(i)) // check if environment of empty cell contains value
		{
			emptyCell->value = i; // if not, assign value to cell
			if (solve(field)) // from this state keep on trying to solve the sudoku
				return true;

			emptyCell->value = 0;
		}
	}

	return false;

}
