//
// Created by Acer V3-772G on 4/30/2020.
//
#include "Film.h"

Film::Film(string titel, string genre, int jahr, int anz, string trailer) {
    this->titel = titel;
    this->genre = genre;
    this->jahr = jahr;
    this->anz_likes = anz;
    this->trailer = trailer;
}

Film::~Film()= default;