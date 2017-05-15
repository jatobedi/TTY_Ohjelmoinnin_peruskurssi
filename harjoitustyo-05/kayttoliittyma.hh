#ifndef KAYTTOLIITTYMA_HH
#define KAYTTOLIITTYMA_HH


#include "resepti_map.hh"
#include "vakiot.hh"
#include <fstream>
#include <string>
#include <regex>

using namespace std;



void kayttoliittyma(Resepti_map& resepti_sailio);
void tulosta_virheilmoitus();
bool onko_syote_ok(const string& syote);

#endif // KAYTTOLIITTYMA_HH
