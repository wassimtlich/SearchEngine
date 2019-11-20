#ifndef IndexDeMots_H
#define IndexDeMots_H
#include<vector>
#include "FichierOcc.h"
using namespace std;

class IndexDeMots
{
public:
    vector <FichierOcc> resultats;
    void triFichierOcc(vector<FichierOcc> &tab)
{
    int i, j;
			for (i = 1; i < tab.size(); ++i) {
				FichierOcc elem = tab[i];
				for (j = i; j > 0
					&& tab[j-1].nbreOcc < elem.nbreOcc;
					j--) {
					tab[j] =
						tab[j-1];
				}
				tab[j] = elem;
}
};
    virtual int positionMot(string )=0;
    virtual int positionFichier(string, int )=0;
    virtual void ajouterFichierIndex(string)=0;
    virtual void afficheResultats(vector <string>,vector <string>)=0;
    IndexDeMots() {};
};
#endif
