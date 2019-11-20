#ifndef MOTOCCS_H
#define MOTOCCS_H
#include <string>
#include<vector>
#include "FichierOcc.h"

using namespace std;

struct MotOccs {
	string mot;
	vector<FichierOcc> fichierOccs;
};
#endif
