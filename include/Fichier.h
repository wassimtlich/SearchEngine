#ifndef FICHIER_H
#define FICHIER_H
#include <fstream>
#include<vector>
using namespace std;
class Fichier{
    public:
    string fichier;
    public:
    vector<string> tabMots=*(new vector<string>) ;
    void ecrire(string);
    Fichier(string );
};
#endif

