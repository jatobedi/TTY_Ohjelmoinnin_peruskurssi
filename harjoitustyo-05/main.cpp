// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-05
// Janne Aare 235645
// janne.aare@student.tut.fi
// Ohjelman toiminta: Tietorakenne, johon voi tallentaa
// tuotteiden rakennuksen hierarkian mukaan. Tätä voi testata
// mukana tulevalla käyttöliittymällä.

#include "reppu.hh"
#include "resepti_map.hh"
#include "tiedostonluku.hh"
#include "kayttoliittyma.hh"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    Resepti_map reseptit;
    if (lue_reseptitiedosto("syote.txt", reseptit)){
        //reseptit.tulosta_materiaalit("Rautalapio");
       kayttoliittyma(reseptit);
    } else {
        cout << "Virhe: Tiedoston luku meni vituiksi" << endl;
    }
}
