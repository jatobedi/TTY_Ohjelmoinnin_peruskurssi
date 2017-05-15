#include "kayttoliittyma.hh"

#include "resepti_map.hh"
#include <fstream>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

void kayttoliittyma(Resepti_map& resepti_sailio){
    regex LOPP_REGEX(LOPPU_REGEX);
    regex REPP_REGEX(REPPU_REGEX);
    regex TULR_REGEX(TULOSTA_R_REGEX);
    regex ASKR_REGEX(ASKAR_REGEX);
    regex TULM_REGEX(TULOSTA_M_REGEX);
    smatch tulos;

    string syoterivi;
          while ( cout << "testikayttoliittyma> " and getline(cin, syoterivi) ) {
              if ( regex_match(syoterivi, tulos, LOPP_REGEX ) ) {
                  cout << "loppu" << endl;
                  break;
              }

              else if ( regex_match(syoterivi, tulos, REPP_REGEX ) ){
                  cout << "reppu" << endl;
              }
              else if ( regex_match(syoterivi, tulos, TULR_REGEX ) ){
                  cout << "tulosta reppu" << endl;
              }

              else if ( regex_match(syoterivi, tulos, ASKR_REGEX ) ){
                  string esine = tulos.str(1);
                  cout << esine << endl;
              }
              else if ( regex_match(syoterivi, tulos, TULM_REGEX ) ){
                  string esine = tulos.str(1);
                  resepti_sailio.tulosta_materiaalit(esine);
              } else {
                  tulosta_virheilmoitus();
              }
          }

}

void tulosta_virheilmoitus(){
    cout << "Virhe: syote ei kelpaa" << endl;
}

bool onko_syote_ok(const string& syote, const sregex_iterator& iter){

    if ( syote == "moi"){
        cout << "no moikka moi" << endl;
    }

    return true;
}

/*
 * const string LOPPU_REGEX = "loppu";
const string REPPU_REGEX = VALILYONTI_REGEX
                            + "reppu"
                            + LISA_MERKKIJONOT_REGEX;
const string TULOSTA_R_REGEX = VALILYONTI_REGEX
                            + "tulostareppu"
                            + VALILYONTI_REGEX;
const string ASKAR_REGEX = VALILYONTI_REGEX
                            + "askarreltavissa"
                            + "[[:space:]]+"
                            + MERKKIJONO_REGEX
                            + VALILYONTI_REGEX;
const string TULOSTA_M_REGEX = VALILYONTI_REGEX
                            + "materiaalit"
                            + "[[:space:]]+"
                            + MERKKIJONO_REGEX
                            + VALILYONTI_REGEX;


                  sregex_iterator iter(syoterivi.begin(), syoterivi.end(), SANA_REGEX);
                  sregex_iterator end;

                  string kasky = tulos.str(1);
                  string tarkennus = tulos.str(1);
                    while ( iter != end ) {
                       onko_syote_ok(iter->str());
                       ++iter;
                    }
                            */
