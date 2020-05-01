//
// Created by Acer V3-772G on 4/30/2020.
//
#include <iostream>
#include "Controller.h"
Controller::Controller() = default;

Controller::~Controller() = default;

void Controller::comandaadmin(int i, admin *rep, user *watchliste) {    /// MENIU ADMIN
    if(i==1)    /// ADD in repo - ADMIN
    {
        string titel,genre,trailer;
        int jahr,anz_likes;
        cout<<"Titel: ";cin>>titel;
        cout<<"Genre: ";cin>>genre;
        cout<<"Erscheinungsjahr: ";cin>>jahr;
        cout<<"Anzahl likes: ";cin>>anz_likes;
        cout<<endl;
        Film f = Film(titel,genre,jahr,anz_likes,trailer);
        rep->add(f);
    } else if (i == 2)  /// DELETE in repo - ADMIN
    {
        string titel; int jahr;
        cout<<"Titel: ";cin>>titel;
        cout<<"Erscheinungsjahr: ";cin>>jahr;
        cout<<endl;
        Film f = Film(titel,"",jahr,0,"");
        rep->del(f);
    } else if (i == 3)  /// EDIT in repo - ADMIN
    {
        string titel;
        int jahr;
        cout<<"Titel: ";cin>>titel;
        cout<<"Erscheinungsjahr: ";cin>>jahr;
        cout<<endl;
        Film f = Film(titel,"",jahr,0,"");
        rep->edit(f);
    } else if (i == 4)  /// Anzeigen - ADMIN
    {
        rep->ansehen();
    }
}


void Controller::comandauser(int i, admin *rep, user *watchliste) {     /// MENIU USER
    if (i == 1)     /// suchen nach genre in adminrepo - USER
    {
        rep->suchen(watchliste);
    } else if (i == 3)  /// DEL din watchlist - USER
    {
        string titel; int jahr;
        cout<<"Titel: ";cin>>titel;
        cout<<"Erscheinungsjahr: ";cin>>jahr;
        Film f = Film(titel,"",jahr,0,"");
        watchliste->del(f);
        cout<<"Apreciati filmul? "<<endl<<"1.Da"<<endl<<"2.Nu"<<endl;
        int x;cin>>x;
        if(x==1){   /// Daca il apreciaza, se incrementeaza nr de like-uri al filmului din repository
           rep->increment(f);
        }
    } else if ( i == 2 )    /// anzeigen watchliste
    {
        watchliste->anzeigen();
    }

}