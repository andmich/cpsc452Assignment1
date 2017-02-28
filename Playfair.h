#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "CipherInterface.h"

using namespace std;

class Playfair : public CipherInterface
{
public:
    virtual void setKey(const string&);
    virtual string encrypt(const string&);
    virtual string decrypt(const string&);
    void printMatrix(FILE* fp);
protected:
	char playMatrix[5][5];
};

#endif
