#include <iostream>
#include <string>

using namespace std;

void tulosta_riveja(int rivien_maara) {
    while (rivien_maara > 0){
        cout << endl;
        rivien_maara --;
    }
}

int main()
{
    string sana = "kellopeliappelsiini";
    string arvattusana = "___________________";
    const int sallitut_virheet = 5;
    int virheet = 0;
    string::size_type mitta = 0;
    mitta = sana.length();

    cout << "Sanassa on " << mitta << " kirjainta." << endl;

    while (sana != arvattusana and
            virheet < sallitut_virheet){
        tulosta_riveja(1);
        cout << "voit erehtyä vielä " << sallitut_virheet - virheet
             << " kertaa" << endl;
        tulosta_riveja(1);

        cout << arvattusana << endl;
        virheet ++;
    }
    tulosta_riveja(2);
    if ( sana == arvattusana ) {
        cout << "Onneksi olkoon, arvasit sanan oikein!" << endl;
    } else {
            cout << "Voi harmin paikka, arvaukset loppuivat kesken!" << endl;
    }

}
