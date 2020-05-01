//
// Created by Acer V3-772G on 5/1/2020.
//

#include "UI.h"
#include "Controller.h"
UI::UI() = default;
UI::~UI() = default;

void UI::program() {
    admin repo = admin();       /// baza de date
    user watchlist = user();    /// watchlistul userului

    Film f1= Film("Seven","Crime",1995,100,"https://www.youtube.com/watch?v=znmZoVkCjpI");
    Film f2= Film("Inception","Sci-Fi",2010,1500,"https://www.youtube.com/watch?v=YoHD9XEInc0");
    Film f3= Film("Matrix","Sci-Fi",1999,10000,"https://www.youtube.com/watch?v=m8e-FF8MsqU");
    Film f4= Film("Godfather","Crime",1972,1000,"https://www.youtube.com/watch?v=sY1S34973zA");
    Film f5= Film("Pulp Fiction","Crime",1994,500,"https://www.youtube.com/watch?v=s7EdQ4FqbhY");
    Film f6= Film("Fight Club","Drama",1999,800,"https://www.youtube.com/watch?v=qtRKdVHc-cE");
    Film f7= Film("Heat", "Thriller",1995,900,"https://www.youtube.com/watch?v=2GfZl4kuVNI");
    Film f8= Film("Casino", "Crime",1995,200,"https://www.youtube.com/watch?v=EJXDMwGWhoA");
    Film f9= Film("Goodfellas", "Biography", 1990, 500, "https://www.youtube.com/watch?v=qo5jJpHtI1Y");
    Film f10= Film("The Silence of the Lambs", "Thriller", 1991, 1000, "https://www.youtube.com/watch?v=W6Mm8Sbe__o");

    repo.add(f1);repo.add(f2);repo.add(f3);repo.add(f4);repo.add(f5);repo.add(f6);repo.add(f7);repo.add(f8);repo.add(f9);
    repo.add(f10);
    cout<<endl<<endl;

    cout<<"0. Exit"<<endl<<"1. Meniu USER"<<endl<<"2. Meniu ADMIN"<<endl;
    int x;cin>>x;
    while(x)
    {
        if(x==1){
            cout<<"Meniu USER"<<endl<<"0. Exit"<<endl<<"1. Suchen nach genre"<<endl<<"2. Show watchlist"<<endl<<"3. Delete from watchlist"<<endl;
            int u;
            cin>>u;
            while(u){
                Controller().comandauser(u, &repo, &watchlist);
                cout<<"Meniu USER"<<endl<<"0. Exit"<<endl<<"1. Suchen nach genre"<<endl<<"2. Show watchlist"<<endl<<"3. Delete from watchlist"<<endl;
                cin>>u;
            }
        }else if (x == 2){
            cout<<"Meniu ADMIN"<<endl<<"0. Exit"<<endl<<"1. ADD Film"<<endl<<"2. DELETE Film"<<endl<<"3. EDIT Film"<<endl<<"4. Show list"<<endl;
            int u;
            cin>>u;
            while(u) {
                Controller().comandaadmin(u, &repo, &watchlist);
                cout<<"Meniu ADMIN"<<endl<<"0. Exit"<<endl<<"1. ADD Film"<<endl<<"2. DELETE Film"<<endl<<"3. EDIT Film"<<endl<<"4. Show list"<<endl;
                cin>>u;
            }
        }
        cout<<endl<<endl;
        cout<<"0. Exit"<<endl<<"1. Meniu USER"<<endl<<"2. Meniu ADMIN"<<endl;
        cin>>x;
    }
}
