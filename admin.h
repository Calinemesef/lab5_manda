//
// Created by Acer V3-772G on 4/30/2020.
//

#ifndef LAB5_ADMIN_H
#define LAB5_ADMIN_H
#pragma once
#include <vector>
#include "Film.h"
#include "user.h"

class admin{
private:
    vector<Film> repo;  /// baza de date cu toate filmele
public:
    admin();
    void ansehen();
    void add(Film);
    void del(Film);
    void edit(Film);
    void suchen(user*);
    void increment(Film);   /// metoda pentru incrementarea nr de like-uri al unui film din repo, atunci cand userul il sterge din watchlist, daca vrea
    ~admin();
};
#endif //LAB5_ADMIN_H
