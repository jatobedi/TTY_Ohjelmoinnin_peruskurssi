#include "tiedostonluku.hh"
#include "resepti_map.hh"
#include <fstream>
#include <string>
#include <regex>

using namespace std;

bool lue_reseptitiedosto(string tiedosto, Resepti_map &resepti_sailio){
    regex RIVI_REGEX(RIVIN_MUOTO_REGEX);
    regex TYHJA_RIVI_REGEX(VALILYONTI_REGEX);
    regex KOMMENTTIRIVI_REGEX(KOMMENTTI_REGEX);

    smatch tulos;

    ifstream file(tiedosto);
    if ( not file ) {
        return false;
    }

    string rivi;
    while ( getline(file, rivi) ) {
        if ( regex_match(rivi, tulos, RIVI_REGEX) ) {
            string esine = tulos.str(1);
            string materiaali = tulos.str(2);

            if ( not lisaa_resepteihin(esine, materiaali, resepti_sailio)){
                return false;
            }
        }
        else if (regex_match(rivi, tulos, TYHJA_RIVI_REGEX)
                 or regex_match(rivi, tulos, KOMMENTTIRIVI_REGEX)){
            continue;
        }
        else {
            return false;
        }
    }

    file.close();
    return true;
}

bool lisaa_resepteihin(const string& esine, const string& materiaali, Resepti_map &resepti_sailio){
    if ( resepti_sailio.loytyyko_materiaali_esineesta(esine, materiaali) ){
        return false;
    } else {
        resepti_sailio.lisaa_alkio(esine, materiaali);
        return true;
    }
}
