#include <iostream>
#include "../include/IndexDeMotsVector.h"
#include "../include/Fichier.h"
using namespace std;
int IndexDeMotsVector::positionMot(string mot)
{
    for (int i = 0; i < index.size(); i++)
    {
        if (mot == index[i].mot)
        {
            return i;
        }
    }

    return -1;
}

int IndexDeMotsVector::positionFichier(string fichier, int j)
{
    for (int i = 0; i < index[j].fichierOccs.size(); i++)
    {
        if (fichier == index[j].fichierOccs[i].nomFichier)
        {
            return i;
        }
    }

    return -1;

}
void IndexDeMotsVector::ajouterFichierIndex(string fichier)
{
    Fichier  file(fichier)   ;
    for(int w=0; w<file.tabMots.size(); w++)
    {
        int j ;
        if ((j = positionMot(file.tabMots[w])) > -1)
        {
            int k;
            if ((k = positionFichier(fichier, j))
                    > -1)
            {
                index[j].fichierOccs[k].nbreOcc++;
            }
            else
            {
                index[j].fichierOccs.push_back(*(new FichierOcc));
                index[j].fichierOccs[index[j].fichierOccs.size()-1].nomFichier = fichier;
                index[j].fichierOccs[index[j].fichierOccs.size()-1].nbreOcc = 1;
            }
        }
        else
        {
            index.push_back((MotOccs)
            {
                file.tabMots[w],
                *(new vector<FichierOcc>)
            });
            int j = index.size()-1;
            int k;
            if ((k = positionFichier(fichier, j))
                    > -1)
            {
                index[j].fichierOccs[k].nbreOcc++;
            }
            else
            {
                index[j].fichierOccs.push_back(*(new FichierOcc));
                index[j].fichierOccs[index[j].fichierOccs.size()-1].nomFichier = fichier;
                index[j].fichierOccs[index[j].fichierOccs.size()-1].nbreOcc = 1;
            }
        }
    }
}

void IndexDeMotsVector::afficheResultats(vector <string> nomsDesFichiers,vector <string> input)
{
    resultats.clear();
    for (int i = 0; i < nomsDesFichiers.size(); i++)
    {
        resultats.push_back((FichierOcc)
        {
            nomsDesFichiers[i],
                            0
        });
        for (int j = 0; j < input.size(); j++)
        {
            int k;
            if ((k = positionMot(input[j])) > -1)
            {
                int l;
                if ((l = positionFichier(
                             nomsDesFichiers[i],
                             k
                         )) > -1)
                {
                    resultats[resultats.size()-1].nbreOcc +=
                        index[k].fichierOccs[l].nbreOcc;
                }
            }
        }
    }
    triFichierOcc(resultats);
    for (int i = 0; i < resultats.size(); i++)
    {
        cout << resultats[i].nomFichier << " "
             << resultats[i].nbreOcc << endl;

    }
}

IndexDeMotsVector::IndexDeMotsVector(vector<string> nomsDesFichiers, vector<string> input)
{
    for(int i=0; i<nomsDesFichiers.size(); i++)
    {
        ajouterFichierIndex(nomsDesFichiers[i]);
    }
    for (int k = 0; k < index.size(); k++)
    {
       triFichierOcc(index[k].fichierOccs);
    }
}
