#ifndef IndexDeMotsVector_H
#define IndexDeMotsVector_H
#include <vector>
#include"IndexDeMots.h"
#include"MotOccs.h"
using namespace std;

class IndexDeMotsVector:public IndexDeMots
{
    vector<MotOccs> index;
public:
    IndexDeMotsVector() {};
    IndexDeMotsVector(vector<string> nomsDesFichiers, vector<string> input);
    int positionMot(string );
    int positionFichier(string, int );
    void ajouterFichierIndex(string );
    void afficheResultats(vector <string>,vector <string>);
};
#endif
