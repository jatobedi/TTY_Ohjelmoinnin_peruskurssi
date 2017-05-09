#include "resepti_map.hh"
#include <iostream>

using namespace std;

int main()
{
    Resepti_map reseptit;
    reseptit.lisaa_materiaali("kattila", "runko");
    reseptit.lisaa_materiaali("pannu", "runko");
    reseptit.lisaa_materiaali("kattila", "kahva");
    reseptit.tulosta_materiaalit("kattila");

}
