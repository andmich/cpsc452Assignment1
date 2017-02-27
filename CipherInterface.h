#ifndef __CIPHER_INTERFACE__
#define __CIPHER_INTERFACE__

#include <string>
#include <iostream>

using namespace std;

class CipherInterface
{
    public:
        CipherInterface(){}

        virtual bool setKey(const string& theKey) { return false; }

        virtual string encrypt(const string& plaintext) { return ""; }

        virtual string decrypt(const string& cipherText) { return ""; }

    protected:
};
#endif
