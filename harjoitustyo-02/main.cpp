// TIE-02200 Ohjelmoinnin peruskurssi.
// harjoitustyo-02
// Janne Aare 235645
// janne.aare@student.tut.fi

#include "kayttoliittyma.hh"
#include "algoritmit.hh"
#include "splitter.hh"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

int main()
{
    ketjut_type ketjut;
    if (lue_tiedosto(ketjut)){
        kayttoliittyma(ketjut);
    }else{
        cout << "Virhe: syötetiedostoa ei saatu luettua."
             << endl;
    }
}
