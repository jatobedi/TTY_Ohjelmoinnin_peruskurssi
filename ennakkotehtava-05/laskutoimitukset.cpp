#include "laskutoimitukset.hh"

double summa(double luku_1, double luku_2){
    return luku_1+luku_2;
}

double erotus(double luku_1, double luku_2){
    return luku_1-luku_2;
}

double tulo(double luku_1, double luku_2){
    return luku_1*luku_2;
}

double osamaara(double luku_1, double luku_2){
    if ( luku_2 != 0.0 ){
        return luku_1/luku_2;
    }else{
        return 0.0;
    }
}
