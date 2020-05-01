//
// Created by Acer V3-772G on 4/30/2020.
//
#include "admin.h"
#include <iostream>

using namespace std;


admin::admin(){
    this->repo = {} ;
}

void admin::ansehen() { /// Afisarea tuturor filmelor din baza de date
    for(auto i= this->repo.begin(); i< this->repo.end();i++){
        cout<<i->get_titel()<<"\tErscheinungsjahr: "<<i->get_jahr()<<"\tGenre: "<<i->get_genre()<<"\t"<<i->get_anz_likes()<<" likes";
        cout<<endl;
    }
}

void admin::add(Film f) {   /// Adaugarea unui film in baza de date(de catre admin), in caz ca nu exista deja in lista
    bool found = false;
    for(auto i= this->repo.begin(); i< this->repo.end();i++) {
        if(i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr()) {
            cout << "Filmul exista deja in lista"<<endl<<endl;
            found = true;
        }
    }
    if(!found) {
        this->repo.push_back(f);
        cout<<"Film adaugat"<<endl;
    }
}

void admin::del(Film f) {   /// Stergerea unui film din baza de date(de catre admin)
    bool found = false;
    for(auto i= this->repo.begin(); i< this->repo.end();i++) {
        if(i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr()) {
            this->repo.erase(i);
            cout<<"Film sters din lista"<<endl<<endl;
            found = true;
        }
    }
    if(!found) {
        cout<<"Filmul nu se afla in lista"<<endl<<endl;
    }
}

void admin::edit(Film f) {  /// Prelucrarea informatiilor legate de un anumit film(de catre admin)
    cout<<"Ce se modifica:"<<endl;
    cout<<"1: Titlul"<<endl<<"2: Anul"<<endl<<"3: Genul"<<endl<<"4: Nr likeuri"<<endl;
    cout<<"0: exit"<<endl<<"Alegeti o tasta: ";
    int x; cin>>x;
    if(x == 0)
        return;
    while(x !=0 ) {
        if(x == 1) {       /// pt tasta 1 se schimba titlul
            cout<<"Titlu nou: ";
            string n;   cin >> n;

            for (auto &i : this->repo) {
                if (i.get_titel() == f.get_titel() &&
                    i.get_jahr() == f.get_jahr()) {       /// gasesc filmul respectiv in lista
                    i.set_titel(n);                                                      /// si ii schimb numele
                    f.set_titel(n);
                    cout<<" Titlu schimbat"<<endl<<endl;
                }
            }

        }
        else if (x == 2) {      /// pt tasta 2 se schimba anul
            cout<<"Anul nou: "; int k;
            cin >> k;
            for (auto &i : this->repo) {
                if (i.get_titel() == f.get_titel() &&
                    i.get_jahr() == f.get_jahr()) {        /// gasesc filmul respectiv in lista
                    i.set_jahr(k);                                                       /// si ii schimb anul
                    f.set_jahr(k);
                    cout<<" An schimbat"<<endl<<endl;

                }
            }
        }
        else if (x == 3) {      /// pt tasta 3 se schimba genul
            cout<<"Genul nou: "; string gen;
            cin >> gen;
            for (auto &i : this->repo) {
                if (i.get_titel() == f.get_titel() &&
                    i.get_jahr() == f.get_jahr()) {        /// gasesc filmul respectiv in lista
                    i.set_genre(gen);                                                  ///si ii schimb genul
                    f.set_genre(gen);
                    cout<<" Gen schimbat"<<endl<<endl;

                }
            }
        }
        else if (x == 4){       /// pt tasta 4 se schimba nr de like-uri
            cout<<" Nr likeuri: "; int n;cin>>n;
            for (auto &i : this->repo) {
                if (i.get_titel() == f.get_titel() &&
                    i.get_jahr() == f.get_jahr()) {        /// gasesc filmul respectiv in lista
                    i.set_anz_likes(n);                                                  ///si ii schimb nr de like-uri
                    f.set_anz_likes(n);
                    cout<<" Numar schimbat"<<endl<<endl;
                }
            }
        }
        cout<<"Mai modificati ceva?"<<endl;
        cout<<"1: Titlul"<<endl<<"2: Anul"<<endl<<"3: Genul"<<endl<<"4: Nr likeuri"<<endl;
        cout<<"0: Exit"<<endl<<"Alegeti o tasta: ";
        cin>>x;
    }
}

void admin::suchen(user* watchliste) {  /// Cautarea unui film dupa gen(de catre user)
    /// Daca se gaseste vreun film, acesta poate fi adaugat de catre user in watchlistul propriu
    cout<<"Gen: ";
    string gen;
    cin.get();
    getline(std::cin,gen);  /// citesc genul
    cout<<endl;
    if(gen.empty()){  /// daca nu se trece niciun gen, se afiseaza toate filmele
        for(auto i= this->repo.begin(); i< this->repo.end();i++){
            cout<<i->get_titel()<<" "<<i->get_jahr()<<" "<<i->get_genre()<<" "<<i->get_anz_likes();
            cout<<endl;
        }
    }
    else {  /// se cauta filme dupa genul respectiv
        bool found=false;
        auto i = this->repo.begin();
        bool go=true;
        while(i!= this->repo.end() && go)
        {        /// se afiseaza cate un film din genul respectiv
                if (i->get_genre() == gen) {
                    found = true;
                    cout << i->get_titel() << " " << i->get_jahr() << " " << i->get_genre() << " "<< i->get_anz_likes();
                    cout << endl;

                    system(string("start " + i->get_trailer()).c_str());    /// afisez trailerul

                    cout << "Daca va place si doriti sa-l adaugati in watchlist apasati tasta 1, daca nu 0" << endl;
                    int x;
                    cin >> x;
                    if (x == 1) {
                        Film f = Film(i->get_titel(), i->get_genre(), i->get_jahr(), i->get_anz_likes(),i->get_trailer());
                        watchliste->add(f); /// Il adaug in watchlist
                    }
                    cout<<"0. Stop searching"<<endl<<"1. Next movie"<<endl;
                    cin>>go;
                }
                i++;
        }
        if(!found){
            cout<<"Niciun film de genul acesta !"<<endl;
        }
    }
}


void admin::increment(Film f) {
    /// Daca atunci cand userul sterge un film din watchlist doreste sa-i dea nota, se incrementeaza nr de like-uri al filmului
    for (auto i = this->repo.begin(); i < this->repo.end(); i++) {
        if(i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr()){
            i->set_anz_likes(i->get_anz_likes()+1);
            cout<<"Numarul de like-uri a fost incrementat"<<endl<<endl;
        }
    }
}

admin::~admin() = default;
