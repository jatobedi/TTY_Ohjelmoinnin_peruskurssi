// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-05
// Janne Aare 235645
// janne.aare@student.tut.fi
// Käyttöliittymä ohjelman testaukseen.

#include "kayttoliittyma.hh"
#include "reppu.hh"
#include "resepti_map.hh"
#include "vakiot.hh"
#include <fstream>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

void kayttoliittyma(Resepti_map& resepti_sailio, Reppu &reppu_sailio){
    // Ottaa käyttäjältä syötteen ja tekee sen perusteella toimintoja.
    // Resepti_map& resepti_sailio:
    // Reppu &reppu_sailio:

    regex LOPETUS_REGEX(LOPPU_REGEX);
    regex LISAA_REGEX(REPPU_REGEX);
    regex TYHJENNA(TYHJENNA_REPPU_REGEX);
    regex REPUN_TULOSTUS_REGEX(TULOSTA_R_REGEX);
    regex ASKARTELU_REGEX(ASKAR_REGEX);
    regex MATERIAALIEN_TULOSTUS_REGEX(TULOSTA_M_REGEX);
    regex TAVARA_REGEX(MERKKIJONO_REGEX);
    smatch tulos;

    string syoterivi;
    while ( cout << "testikayttoliittyma> " and getline(cin, syoterivi) ) {
        if ( regex_match(syoterivi, tulos, LOPETUS_REGEX ) ) {
            resepti_sailio.tuhoa_taulukot();
            break;
        }

        else if ( regex_match(syoterivi, tulos, TYHJENNA ) ){
            reppu_sailio.tyhjenna();
            cout << "Reppu tyhjennetty." << endl;
        }

        else if ( regex_match(syoterivi, tulos, LISAA_REGEX ) ){
            reppu_sailio.tyhjenna();

            sregex_iterator iter(syoterivi.begin(),
                                 syoterivi.end(), TAVARA_REGEX);
            sregex_iterator end;

            ++iter;

            bool lisays_ok = true;

            while ( iter != end ) {
                lisays_ok = reppu_sailio.lisaa_tavara(iter->str());
                if ( lisays_ok ){
                    ++iter;
                } else {
                    break;
                }
            }
            if ( lisays_ok ){
                cout << "Repun sisalto asetettu." << endl;
            }
        }
        else if ( regex_match(syoterivi, tulos, REPUN_TULOSTUS_REGEX ) ){
            reppu_sailio.tulosta();
        }

        else if ( regex_match(syoterivi, tulos, ASKARTELU_REGEX ) ){
            string esine = tulos.str(1);

            if ( virhesyote(esine, resepti_sailio) ){
                tulosta_virheilmoitus();
                continue;
            }

            if ( reppu_sailio.onko_askarreltavissa(esine) ){
                cout << "On askarreltavissa." << endl;
            } else {
                cout << "Ei ole askarreltavissa." << endl;
            }
        }
        else if ( regex_match(syoterivi, tulos, MATERIAALIEN_TULOSTUS_REGEX) ){
            string esine = tulos.str(1);

            if ( virhesyote(esine, resepti_sailio) ){
                tulosta_virheilmoitus();
                continue;
            }
            resepti_sailio.tulosta_materiaalit(esine);

        } else {
            tulosta_virheilmoitus();
        }
    }
}

void tulosta_virheilmoitus(){
    // Tulostaa virheilmoituksen.

    cout << "Virhe: syote ei kelpaa" << endl;
}

bool virhesyote(const string& syote, Resepti_map &resepti_sailio){
    // Tutkii, löytyykö syotteen esine lähdetiedosta.
    // const string& syote: Tutkittava sana.
    // Resepti_map &resepti_sailio: Lähdetietosäiliö.
    // return true: jos esinettä ei löydy lähdetidosta,
    // eikä ole siis hyväksyttävä.
    // return false: jos esine on hyväksyttävä.

    if ( resepti_sailio.loytyyko_esine_resepteista(syote) ){
        return false;
    }
    return true;
}

