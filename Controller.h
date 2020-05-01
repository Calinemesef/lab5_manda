//
// Created by Acer V3-772G on 4/30/2020.
//

#ifndef LAB5_CONTROLLER_H
#define LAB5_CONTROLLER_H
#pragma once
#include "Film.h"
#include "admin.h"
#include "user.h"
class Controller{
public:
    Controller();
    void comandaadmin(int, admin*, user*);  /// Metodele meniului de ADMIN
    void comandauser(int, admin*, user*);   /// Metodele meniului de USER
    ~Controller();
};
#endif //LAB5_CONTROLLER_H
