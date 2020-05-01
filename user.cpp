//
// Created by Acer V3-772G on 4/30/2020.
//

#include "user.h"
#include <iostream>
using namespace std;

user::user(){
    this->repo = {} ;
}


void user::del(Film f) {    /// DELETE din watchlist( pentru user)
    if(this->repo.empty())
        cout<<" Lista goala!"<<endl;
    else {
        bool found = false;
        for (auto i = this->repo.begin(); i < this->repo.end(); i++) {
            if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr()) { /// daca il gasesc in watchlist
                this->repo.erase(i);                                                /// il sterg
                cout << "Film sters din watchlist" <<endl<<endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Filmul nu se afla in lista"<<endl<<endl;
        }
    }
}

void user::anzeigen() { /// Afisarea watchlistului userului
    if(this->repo.empty())
        cout<<" Lista goala!"<<endl<<endl;
    else
        for(auto i= this->repo.begin(); i< this->repo.end();i++) {
            cout<<i->get_titel()<<"\tErscheinungsjahr: "<<i->get_jahr()<<"\tGenre: "<<i->get_genre()<<"\t"<<i->get_anz_likes()<<" likes";
            cout<<endl;
        }
}

void user::add(Film f) {    /// Metoda care se apeleaza dupa ce userul vede trailerul unui film,
                            /// doar in caz ca acesta doreste sa adauge filmul respectiv in watchlist, daca nu e deja
    bool found = false;
    for(auto i= this->repo.begin(); i< this->repo.end();i++) {
        if(i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr()) {
            cout << "Filmul exista deja in watchlist"<<endl<<endl;
            found = true;
        }
    }
    if(!found) {
        this->repo.push_back(f);
        cout<<"Film adaugat in watchlist"<<endl<<endl;
    }

}

user::~user() = default;
