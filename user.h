//
// Created by Acer V3-772G on 4/30/2020.
//

#ifndef LAB5_USER_H
#define LAB5_USER_H
#pragma once
#include <vector>
#include "Film.h"
class user{
private:
    vector<Film> repo;  /// watchlist-ul userului
public:
    user();
    void add(Film);
    void del(Film);
    void anzeigen();
    ~user();
};
#endif //LAB5_USER_H
