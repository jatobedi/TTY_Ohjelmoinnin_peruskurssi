//------------------------------------------------
//  TIE-02200 Ohjelmoinnin peruskurssi -mallikoodi
//  Copyright © 2017  opersk@tut.fi
//------------------------------------------------

#ifndef TIEDOSTONLUKU_HH
#define TIEDOSTONLUKU_HH

#include "todo_rakenne.hh"
#include <fstream>
#include <iostream>

using namespace std;


bool lue_tehtavatiedosto(ifstream& tiedosto, Todo& tehtavarakenne);
void lue_rivi(ifstream& virta, Todo& tehtavarakenne, bool& virheeton);
bool tarkista_kentat(string& numero_kentta,string& tehtava_kentta);
string::size_type laskuri(string& rivi, string::iterator iter);


#endif
