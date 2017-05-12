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
    reseptit.lisaa_materiaali("hiilta", "puuta");
    reseptit.lisaa_materiaali("rautaharkkoja", "rautamalmia");
    reseptit.lisaa_materiaali("lautaa", "puuta");
    reseptit.lisaa_materiaali("rautalapio", "lapionvarsi");
    reseptit.lisaa_materiaali("rautalapio", "lautaa");
    reseptit.lisaa_materiaali("rautalapio", "rautaharkkoja");
    reseptit.lisaa_materiaali("rautaharkkoja", "hiilta");
    reseptit.lisaa_materiaali("lapionvarsi", "lautaa");
    reseptit.tulosta();
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
