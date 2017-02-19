#ifndef SPLITTER_HH
#define SPLITTER_HH

//------------------------------------------------
//  TIE-02200 Ohjelmoinnin peruskurssi -mallikoodi
//  Copyright Â© 2017  opersk@tut.fi
//------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

const unsigned int SPLITTER_VIRHE = 0;

class Splitter {
  public:
    Splitter(const string& paloiteltava_merkkijono = "");
    void aseta_paloiteltava_merkkijono(const string& merkkijono);
    unsigned int paloittele(char erotinmerkki, bool ohita_tyhjat = false);
    unsigned int kenttien_lukumaara() const;
    string hae_kentta(unsigned int kentan_numero) const;

  private:
    string paloiteltava_;
    vector<string> kentat_;
};

#endif // SPLITTER_HH
