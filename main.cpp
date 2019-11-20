#include <iostream>
#include "include/FichierOcc.h"
#include "include/Fichier.h"
#include "include/MotOccs.h"
#include "include/Fichier.h"
#include "include/IndexDeMots.h"
#include "include/IndexDeMotsMap.h"
#include "include/IndexDeMotsVector.h"
#include<sstream>
using namespace std;


int main()
{
    string ch,ch2;

    Fichier file("fichiersdelabase.txt");
    IndexDeMotsMap indexDeMots;
    for(int i=0 ; i<file.tabMots.size(); i++)
    {
        indexDeMots.ajouterFichierIndex(file.tabMots[i]);
    }
    vector<string> mots_cles;
    int x , y=-1, z=-1 ,q=-1,w=-1,j=0, k =0;
    cout<<"\n\n ***************** MOTEUR DE RECHERCHE ***************** \n\n\n";
    cout<<  "                   MENU DE L'APPLICATION \n\n";
    do
    {
        cout<< "TAPEZ : \n1- Pour gerer la base de recherche \n2- Pour rechercher un fichier texte dans la base \n0- Pour quitter l'application \n\n";
        cin>>x;
        switch (x)
        {
        case 0 :
        {
            cout<<"\n\n******** AU REVOIR ********\n\n";
            break;
        }
        case 1 :
        {
            do
            {
                cout<<"TAPEZ : \n1-Pour ajouter un fichier a la base de recherche \n2-Pour afficher  tout les fichiers \n0- Pour retourner au menu principal \n\n ";
                cin>>y ;
                switch(y)
                {
                case   1:
                {
                    do
                    {
                        cout<<"\nTAPEZ :  \n0-Pour retourner au menu precedent \n1-Pour ajouter un fichier a la base de recherche \n\n ";
                        cin>>q;
                        switch (q)
                        {
                        case 0:
                        {
                            cout<<"\n      Retour au menu precedent \n";
                            break ;
                        }
                        case 1 :
                        {
                            cin>>ch;
                            indexDeMots.ajouterFichierIndex(ch);
                            file.ecrire(ch);
                            break ;
                        }
                        default :
                        {
                            cout<< "Vous avez donne un mauvais choix \n\n" ;
                            break ;
                        }
                        }
                    }
                    while (q!=0);
                    break ;
                }
                case 2 :
                {
                    do
                    {
                        cout<<"TAPEZ : \n0-Pour retourner au menu precedent \n1-Pour affichier tout les fichiers \n \n";
                        cin>>w;
                        switch(w)
                        {
                        case 0 :
                        {
                            cout<<"\n        Retour au menu precedent\n\n ";
                            break ;
                        }
                        case 1 :
                        {
                            Fichier fil("fichiersdelabase.txt") ;
                            if (fil.tabMots.size()==0) cout<< "\n Pas de fichiers pour l'instant ! Priere  d ajouter des fichiers a la base \n \n ";
                            else
                            {

                                cout<<"\n\n Les fichiers sont :"<<endl ;
                                for(int i=0; i<fil.tabMots.size(); i++)
                                {
                                    cout<<fil.tabMots[i]<<endl;
                                }
                            }

                            break ;
                        }
                        default :
                        {
                            cout<< "Vous avez donne un mauvais choix \n\n" ;
                            break ;
                        }
                        }
                    }
                    while(w!=0);
                    break ;
                }
                case 0 :
                {
                    cout<<"            Retour au menu principale\n\n";
                    break ;
                }
                default :
                {
                    cout<< "Vous avez donne un mauvais choix \n\n" ;
                    break ;
                }
                }
            }
            while(y!=0);
            break ;
        }
        case 2 :
        {
            do
            {
                cout<<"TAPEZ : \n0-Pour retourner au menu principale\n1-Pour saisir les mots cles  \n\n";
                cin>>z;
                switch(z)
                {
                case 1:
                { cin.ignore();
                    getline(cin,ch2);
                    istringstream aux(ch2);
                    string ch1;
                    while(aux>>ch1)
                    {
                    mots_cles.push_back(ch1);
                    }
                    Fichier file("fichiersdelabase.txt");
                    indexDeMots.afficheResultats(file.tabMots,mots_cles);
                    break;

                }
                case 0:
                {
                    cout<<"            Retour au menu principale\n\n";
                    break;
                }
                default :
                {
                    cout<< "Vous avez donne un mauvais choix \n\n" ;
                    break ;
                }
                }
            }
            while(z!=0);
            break ;
        }
        default :
        {
            cout<<"Vous avez donne un mauvais choix\n";
            break ;
        }
        }
    }
    while(x!=0);
    return 0;
}

