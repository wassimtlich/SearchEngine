#ifndef IndexDeMotsMap_H
#define IndexDeMotsMap_H
#include <map>
#include "IndexDeMots.h"
using namespace std;

class IndexDeMotsMap: public IndexDeMots
{
    map<string,vector<FichierOcc>> index;
public:
    IndexDeMotsMap() {};
    IndexDeMotsMap(vector<string> , vector<string>);
    int positionMot(string);
    int positionFichier(string, int );
    void ajouterFichierIndex(string);
    void afficheResultats(vector <string>,vector <string>);

};
#endif

