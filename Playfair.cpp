#include "Playfair.h"

void Playfair::setKey(const string& key)
{
	//initialize playMatrix
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			playMatrix[x][y] = ' ';
		}
	}

	string alpha = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

	int keyPos = 0;
	int row = 0;
	int col = 0;
	int j = 0;

	char keyChar = ' ';
	while (j < key.length())
	{
		bool found = false;
		int i = 0;

		if (key.at(j) == 'j' || key.at(j) == 'J')
			keyChar = 'I';
		else
			keyChar = toupper(key.at(j));
		while (!found)
		{
			if (alpha.at(i) == keyChar)
			{
				alpha.at(i) = ' ';
				found = true;
			}
			i++;
		}
		if (col == 5)
		{
			row++;
			col = 0;
		}
		if (found)
		{
			playMatrix[row][col] = toupper(key.at(j));
			col++;
			j++;
		}
	}

	j = 0;
	while (j < alpha.length())
	{
		if (alpha.at(j) != ' ')
		{
			playMatrix[row][col] = alpha.at(j);
			col++;
		}
		j++;

		if (col == 5)
		{
			row++;
			col = 0;
		}
	}
}

string Playfair::encrypt(const string& plaintext)
{
	string cipherText;

	int j = 2;
    int row = 0;
    int col = 0;
    int firstRow = -1;
    int firstCol = -1;
    int secondRow = -1;
    int secondCol = -1;
	for (int i = 0; i < plaintext.length() - 2; i+=2)
	{
		string temp = plaintext.substr(i, j);
		bool found = false;
		while (!found)
		{
            if (playMatrix[row][col] == toupper(temp.at(0)))
            {
                firstRow = row;
                firstCol = col;
            }
            if (playMatrix[row][col] == toupper(temp.at(1)))
            {
                secondRow = row;
                secondCol = col;
            }
            col++;
            if (col == 5)
    		{
    			row++;
    			col = 0;
    		}
            if (firstRow >= 0 && secondRow >= 0)
                found = true;
		}

        cipherText = cipherText + playMatrix[firstRow][secondCol] + playMatrix[secondRow][secondCol];
	}
	return "";
}

string Playfair::decrypt(const string& ciphertext)
{
	return "";
}
