#ifndef TIEDOSTONLUKU_HH
#define TIEDOSTONLUKU_HH

#include "resepti_map.hh"
#include "vakiot.hh"
#include <fstream>
#include <string>
#include <regex>

using namespace std;

bool lue_reseptitiedosto(string tiedosto, Resepti_map& resepti_sailio);
bool lisaa_resepteihin(const string& esine, const string& materiaali, Resepti_map &resepti_sailio);

#endif // TIEDOSTONLUKU_HH
