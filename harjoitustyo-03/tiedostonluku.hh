//------------------------------------------------
//  TIE-02200 Ohjelmoinnin peruskurssi -mallikoodi
//  Copyright © 2017  opersk@tut.fi
//------------------------------------------------

#ifndef TIEDOSTONLUKU_HH
#define TIEDOSTONLUKU_HH

#include "todo_rakenne.hh"
#include <fstream>


using namespace std;


bool lue_tehtavatiedosto(ifstream& tiedosto, Todo& tehtavarakenne);
void lue_rivi(ifstream& virta, Todo& tehtavarakenne, bool& virheeton);
bool tarkista_kentat(const int &kiireellisyys, const string &kaskykentta);


#endif
