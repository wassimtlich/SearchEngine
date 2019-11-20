#include "../include/Fichier.h"
using namespace std;
Fichier::Fichier(string nomFichier)
{
    ifstream fichier(nomFichier, ios::in);
    this->fichier = nomFichier;
    if(fichier)
    {
        string ch;
        while(fichier>>ch)
        {
            tabMots.push_back(ch);

        }
    }
    fichier.close();
}
void Fichier::ecrire(string ch)
{
    ofstream file(fichier, ios::app);
    if(file)
    {
        file<<" "<<ch;

    }
    file.close();
}
