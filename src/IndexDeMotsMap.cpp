#include<iostream>
#include "../include/IndexDeMotsMap.h"
#include "../include/Fichier.h"
using namespace std;
int IndexDeMotsMap::positionMot(string mot)
{
    map<string,vector<FichierOcc>>::iterator i=index.begin();
    for(i=index.begin(); i!=index.end(); ++i)
    {
        if (mot == i->first)
        {
            return distance(index.begin(), i);
        }
    }

    return -1;
};

int IndexDeMotsMap::positionFichier(string fichier, int j)
{
    map<string,vector<FichierOcc>>::iterator i=index.begin();
    advance(i,j);
    for (int k = 0; k < i->second.size(); k++)
    {
        if (fichier == i->second[k].nomFichier)
        {
            return k;
        }
    }

    return -1;

};
void IndexDeMotsMap::ajouterFichierIndex(string fichier)
{
    Fichier  file(fichier)   ;
    for(int w=0; w<file.tabMots.size(); w++)
    {
        int j ;
        if ((j = positionMot(file.tabMots[w])) > -1)
        {
            int k;
            map<string,vector<FichierOcc>>::iterator i=index.begin();
            advance(i,j);
            if ((k = positionFichier(fichier, j))
                    > -1)
            {

                i->second[k].nbreOcc++;
            }
            else
            {
                i->second.push_back(*(new FichierOcc));
                i->second[i->second.size()-1].nomFichier = fichier;
                i->second[i->second.size()-1].nbreOcc = 1;
            }
        }
        else
        {
            index[file.tabMots[w]]=*(new vector<FichierOcc>);
            index[file.tabMots[w]].push_back(*(new FichierOcc));
            index[file.tabMots[w]][index[file.tabMots[w]].size()-1].nomFichier = fichier;
            index[file.tabMots[w]][index[file.tabMots[w]].size()-1].nbreOcc = 1;
        }

    }
};

void IndexDeMotsMap::afficheResultats(vector <string> nomsDesFichiers,vector <string> input)
{
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
                    map<string,vector<FichierOcc>>::iterator i=index.begin();
                    advance(i,k);
                    resultats[resultats.size()-1].nbreOcc +=
                        i->second[l].nbreOcc;
                }
            }
        }
    }
    triFichierOcc(resultats);
    for(int i=0; i<nomsDesFichiers.size(); i++)
    {
        ajouterFichierIndex(nomsDesFichiers[i]);
    }
    for (int k = 0; k < index.size(); k++)
    {
        map<string,vector<FichierOcc>>::iterator i=index.begin();
        advance(i,k);
        triFichierOcc(i->second);
    }
    for (int i = 0; i < resultats.size(); i++)
    {
        cout << resultats[i].nomFichier << " "
             << resultats[i].nbreOcc << endl;

    }

};
