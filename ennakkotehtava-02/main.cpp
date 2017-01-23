// TIE-02200 Ohjelmoinnin peruskurssi K2017
// ennakkotehtava-02
// Janne Aare 235645
// janne.aare@student.tut.fi



#include <iostream>
#include <iomanip>
#include <string>
#include <deque>

using namespace std;

class Kellonaika {
public:
    Kellonaika(int tunti, int minuutti);
    void tiktok();
    int hae_tunti() const;
    int hae_minuutti() const;
    void tulosta() const;
    int aikaero(Kellonaika toka);
    void lisaa_vrk();
    int hae_kuluneet_minuutit() const;

private:
    int kuluneet_minuutit_;
};

void pyyda_aika(deque<int>& aika, string viesti){
    string syote;
    cout << viesti;
    getline(cin, syote);
    aika[0] = stoi(syote.substr(0,2));
    aika[1] = stoi(syote.substr(3,2));
    
}

int main(){
    deque<int> aika;
    pyyda_aika(aika, "Anna aika (muodossa tunnit.minutit): ");

    Kellonaika aika1(aika[0], aika[1]);

    pyyda_aika(aika, "Anna toinen aika (muodossa tunnit.minutit): ");

    Kellonaika aika2(aika[0], aika[1]);

    int ero = aika1.aikaero(aika2);

    cout << ero << endl;


}

Kellonaika::Kellonaika(int tunti, int minuutti):
    kuluneet_minuutit_(60 * tunti + minuutti){

}

void Kellonaika::tiktok() {
    ++kuluneet_minuutit_;
    if ( kuluneet_minuutit_ >= 24 * 60 ) {
        kuluneet_minuutit_ = 0;
    }
}

int Kellonaika::hae_tunti() const {
    return kuluneet_minuutit_ / 60;
}

int Kellonaika::hae_minuutti() const {
    return kuluneet_minuutit_ % 60;
}

void Kellonaika::tulosta() const {
    cout << setw(2) << setfill('0') << hae_tunti()
         << ":"
         << setw(2) << hae_minuutti()
         << endl;
}

int Kellonaika::aikaero(Kellonaika toka){

    if (kuluneet_minuutit_ > toka.hae_kuluneet_minuutit()){
    return 24 * 60 - kuluneet_minuutit_ + toka.hae_kuluneet_minuutit();

    } else {
        return toka.hae_kuluneet_minuutit() - kuluneet_minuutit_;
    }
}

void Kellonaika::lisaa_vrk(){
    kuluneet_minuutit_ += 24 * 60;
}

int Kellonaika::hae_kuluneet_minuutit() const {
    return kuluneet_minuutit_;
}
