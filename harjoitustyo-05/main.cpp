// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-05
// Janne Aare 235645
// janne.aare@student.tut.fi
// Ohjelman toiminta: Tietorakenne, johon voi tallentaa
// tuotteiden rakennushierarkian. Tätä voi testata
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
    string tiedostonimi;

    if (cout << "Syotetiedosto: "
            and getline(cin, tiedostonimi)
            and lue_reseptitiedosto(tiedostonimi, reseptit)){

        cout << "Tuotantoketjut luettu onnistuneesti." << endl;

        Reppu reppu(reseptit);
        kayttoliittyma(reseptit, reppu);
    } else {
        cout << "Virhe: Tiedoston luku epaonnistui." << endl;
    }
}
