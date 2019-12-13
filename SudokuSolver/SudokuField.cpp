#include "pch.h"
#include "SudokuField.h"


SudokuField::SudokuField(string input)
{
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	input.erase(remove(input.begin(), input.end(), ','), input.end()); // format input data
	if (input.length() == 81)
	{
		InputValid = true;
		for (short i = 0; i < gridSize; i++) // create data structures
		{
			blocks[i] = new Block();
			rows[i] = new SudokuVector();
			cols[i] = new SudokuVector();
		}

		saveData(input);
	}
}


SudokuField::~SudokuField()
{
}

void SudokuField::showData()
{
	for (short i = 0; i < gridSize; i++)
	{
		if (i % 3 == 0)
			cout << " =========================================" << endl;
		else
			cout << " -----------------------------------------" << endl;
		rows[i]->showData();
	}
	cout << " =========================================" << endl;
}

SudokuEntry* SudokuField::getUnassignedCell()
{
	for (short i = 0; i < gridSize; i++)
	{
		SudokuEntry* unassignedCell = blocks[i]->getUnassignedCell();
		if (unassignedCell)
			return unassignedCell;
	}

	return nullptr;
}

void SudokuField::createRowsAndCols(SudokuEntry* entries[])
{
	short entryIndex = 0;
	for (short rowIndex = 0; rowIndex < gridSize; rowIndex++) // Go through the rows of the field
	{
		for (short colIndex = 0; colIndex < gridSize; colIndex++, entryIndex++) // go through the columns of the field
		{
			entries[entryIndex]->row = rows[rowIndex];
			rows[rowIndex]->addValue(entries[entryIndex], colIndex);
			entries[entryIndex]->col = cols[colIndex];
			cols[colIndex]->addValue(entries[entryIndex], rowIndex);
		}
	}
}

void SudokuField::createBlocks(SudokuEntry* entries[])
{
	short inputIndex = 0;

	for (short blockIndex = 0; blockIndex < gridSize; blockIndex += 3) // go through the 3 lines of blocks
	{
		for (short linePos = 0; linePos < 27; linePos++, inputIndex++) // each line of blocks contains 3*gridSize=27 inputs
		{
			switch (linePos % gridSize)
			{
			case 0:
			case 1:
			case 2:
				entries[inputIndex]->block = blocks[blockIndex];
				blocks[blockIndex]->addValue(entries[inputIndex]);
				break;
			case 3:
			case 4:
			case 5:
				entries[inputIndex]->block = blocks[blockIndex + 1];
				blocks[blockIndex + 1]->addValue(entries[inputIndex]);
				break;
			case 6:
			case 7:
			case 8:
				entries[inputIndex]->block = blocks[blockIndex + 2];
				blocks[blockIndex + 2]->addValue(entries[inputIndex]);
				break;
			default:
				break;
			}
		}
	}

}

void SudokuField::saveData(string input)
{
	SudokuEntry* entries[81];
	for (short i = 0; i < 81; i++)
		entries[i] = new SudokuEntry((int)input[i] - 48, i);

	createRowsAndCols(entries);
	createBlocks(entries);
}
