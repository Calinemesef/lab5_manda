//
// Created by Acer V3-772G on 4/30/2020.
//

#ifndef LAB5_FILM_H
#define LAB5_FILM_H
#pragma once
#include <string>
using namespace std;
class Film{
private:
    string titel;
    string genre;
    int jahr;
    int anz_likes;
    string trailer;
public:
    Film(string,string,int,int,string); /// constructor
    /// metode de get si set pentru atributele obiectului
    void set_titel(string t){ this->titel = t;};
    void set_genre(string g){ this->genre = g;};
    void set_jahr(int j){ this->jahr = j;};
    void set_anz_likes(int a){ this->anz_likes = a;};
    void set_trailer(string t){ this->trailer = t;};

    string get_titel(){ return this->titel;};
    string get_genre(){ return this->genre;};
    int get_jahr(){ return this->jahr;};
    int get_anz_likes(){ return this->anz_likes;};
    string get_trailer(){ return this->trailer;};

    ~Film();
};
#endif //LAB5_FILM_H
