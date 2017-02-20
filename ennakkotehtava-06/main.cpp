// TIE-02200 Ohjelmoinnin peruskurssi
// ennakkotehtava-06
// Janne Aare 235645
// janne.aare@student.tut.fi


#include <iostream>
#include <map>


using namespace std;

int laske_nimet(const map<string, string>& puhelinluettelo,
                    char nimen_alkukirjain, map<string, string>::const_iterator iter){
    if ( iter == puhelinluettelo.end() ){
        return 0;
    }else{
        int lukumaara = 0;
        if ( iter->first.at(0) == nimen_alkukirjain ) {
            ++lukumaara;
        }
        ++iter;
        return lukumaara + laske_nimet(puhelinluettelo, nimen_alkukirjain, iter);
    }
}


int main()
{
    map<string, string> puhelinluettelo = {
        {"Janne", "0443736074"},
        {"Panne", "0443736074"},
        {"Jonne", "0443736074"},
        {"Yvonne", "0443736074"},
        {"Saanne", "0443736074"},
        {"Anne", "0443736074"},
        {"Hanne", "0443736074"},
        {"Aune", "0443736074"}
    };
    map<string, string>::const_iterator iter = puhelinluettelo.begin();
    int nimet = laske_nimet(puhelinluettelo, 'J', iter);
    cout << nimet << endl;
}
