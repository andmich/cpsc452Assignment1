#include "Playfair.h"

bool Playfair::setKey(const string& key)
{
    queue<char> temp;

    int keyPos = 0;
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            //if keyPos isnt equal to key length the continue
            //inserting key into playMatrix otherwise
            //use temp queue to populate matrix
            if (keyPos != key.length())
            {
                //if element in playMatrix is not null then
                //see if character in key is in the playMatrix
                //if not then populate matrix with character from key
                //and push the element replaced into temp queue
                if (playMatrix[row][col] != ' ')
                {
                    int i = row;
                    int j = col;
                    bool done = false;

                    //store char in key
                    char keyChar = ' ';

                    if (key.at(keyPos) == 'J' || key.at(keyPos) == 'j')
                    {
                        keyChar = 'I';
                    }
                    else
                        keyChar = toupper(key.at(keyPos));

                    while (!done && i < 5)
                    {
                        if (playMatrix[i][j] == keyChar)
                        {
                            playMatrix[i][j] = ' ';
                            done = true;
                        }
                        else
                        {
                            j++;
                        }

                        if (j == 5)
                        {
                            i++;
                            j = 0;
                        }
                    }

                    if (done)
                    {
                        temp.push(playMatrix[row][col]);
                        playMatrix[row][col] = toupper(key.at(keyPos));
                        keyPos++;
                    }
                }
                else
                {
                    playMatrix[row][col] = toupper(key.at(keyPos));
                    keyPos++;
                }
            }
            else
            {
                //use vector
            }
        }
    }

    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << playMatrix[row][col];
        }
        cout << endl;
    }
    return false;
}

string Playfair::encrypt(const string& plaintext)
{
    return "";
}

string Playfair::decrypt(const string& ciphertext)
{
    return "";
}
