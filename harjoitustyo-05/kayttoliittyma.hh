// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-05
// Janne Aare 235645
// janne.aare@student.tut.fi
// Käyttöliittymä ohjelman testaukseen.

#ifndef KAYTTOLIITTYMA_HH
#define KAYTTOLIITTYMA_HH

#include "reppu.hh"
#include "resepti_map.hh"
#include "vakiot.hh"
#include <fstream>
#include <string>
#include <regex>

using namespace std;

void kayttoliittyma(Resepti_map& resepti_sailio, Reppu& reppu_sailio);
void tulosta_virheilmoitus();
bool virhesyote(const string& syote, Resepti_map& resepti_sailio);

#endif // KAYTTOLIITTYMA_HH
