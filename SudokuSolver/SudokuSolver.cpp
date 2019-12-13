#include "pch.h"
#include "SudokuField.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

bool solve(SudokuField* field);

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
	
	SudokuField* field = new SudokuField(input);
	if (field->InputValid)
	{
		cout << "Input: " << endl;
		field->showData();

		auto timeStart = chrono::high_resolution_clock::now();
		if (solve(field))
		{
			auto timeEnd = chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
			cout << "Solution:" << endl;
			field->showData();
			cout << "Time needed to calculate: " << duration << "ms" << endl;
		}
		else
			cout << "No solution possible" << endl;
	}
	else
		cout << "There were no 81 input values given. Please check your input." << endl;
}

bool solve(SudokuField* field) // backtracking algorithm
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
