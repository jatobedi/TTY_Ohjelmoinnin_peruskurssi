// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-05
// Janne Aare 235645
// janne.aare@student.tut.fi
// Käyttöliittymän ja tiedostonluvun
// tarvitsemia regex-ilmauksia.

#ifndef VAKIOT_HH
#define VAKIOT_HH

#include <string>
#include <regex>

using namespace std;

// Yhteiset ilmaukset.
const string VALILYONTI_REGEX = "[[:space:]]*";
const string MERKKIJONO_REGEX = "([_a-zA-Z]+)";

// Käyttöliittymän käskyt.
const string LISA_MERKKIJONOT_REGEX =
        "([[:space:]]+[_a-zA-Z]+[[:space:]]*)*";
const string LOPPU_REGEX = VALILYONTI_REGEX
        + "loppu"
        + VALILYONTI_REGEX;
const string REPPU_REGEX = VALILYONTI_REGEX
        + "reppu"
        + LISA_MERKKIJONOT_REGEX;
const string TYHJENNA_REPPU_REGEX = VALILYONTI_REGEX
        + "reppu"
        + VALILYONTI_REGEX;
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

// Tiedoston lukuun liittyvät ilmaukset.
const string KOMMENTTI_REGEX = VALILYONTI_REGEX +
        "#([[:space:]]*[^[:space:]]*[[:space:]]*)*";
const string RIVIN_MUOTO_REGEX = VALILYONTI_REGEX
        + MERKKIJONO_REGEX
        + VALILYONTI_REGEX
        + ":"
        + VALILYONTI_REGEX
        + MERKKIJONO_REGEX
        + VALILYONTI_REGEX;

#endif // VAKIOT_HH
