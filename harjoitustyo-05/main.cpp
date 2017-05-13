// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-05
// Janne Aare 235645
// janne.aare@student.tut.fi
// Ohjelman toiminta: Tietorakenne, johon voi tallentaa
// tuotteiden rakennuksen hierarkian mukaan. Tätä voi testata
// mukana tulevalla käyttöliittymällä.

#include "reppu.hh"
#include "resepti_map.hh"
#include <iostream>

using namespace std;

int main()
{

    Resepti_map reseptit;
    reseptit.lisaa("hiilta", "puuta");
    /*reseptit.lisaa("rautaharkkoja", "rautamalmia");
    reseptit.lisaa("lautaa", "puuta");
    reseptit.lisaa("rautalapio", "lapionvarsi");
    reseptit.lisaa("rautalapio", "lautaa");
    reseptit.lisaa("rautalapio", "rautaharkkoja");
    reseptit.lisaa("rautaharkkoja", "hiilta");
    reseptit.lisaa("lapionvarsi", "lautaa");*/
    reseptit.tulosta_esineet();
    //reseptit.tulosta_materiaalit("Rautaharkkoja");

    Reppu reppu(reseptit);
   // reppu.lisaa_tavara("runko");
   // reppu.lisaa_tavara("runko");
  // reppu.lisaa_tavara("run");
  // reppu.lisaa_tavara("ru");
   // reppu.lisaa_tavara("r");
  // reppu.lisaa_tavara("run");
  //  reppu.tulosta();


}
