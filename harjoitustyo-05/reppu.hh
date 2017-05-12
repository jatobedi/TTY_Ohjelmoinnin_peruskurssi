#ifndef REPPU_HH
#define REPPU_HH

#include "resepti_map.hh"
#include <string>
#include <memory>

using namespace std;

class Reppu
{
public:
    Reppu(Resepti_map reseptit);
    void tulosta();
    bool lisaa_tavara(const string &tavaran_nimi);
    void tyhjenna();
    bool onko_askarreltavissa(const string& tuote);

private:
    struct Reppu_alkio {
        string tavara;
        shared_ptr<Reppu_alkio> seuraava_tav;
    };

    shared_ptr<Reppu_alkio> ensimmainen_tavara_;
    Reppu_alkio* viimeinen_tavara_;
    int lkm_;
    Resepti_map reseptit_;

    bool etsi_resepteista(const string& tavara);
    bool etsi_repusta(const string& tavara);
};

#endif // REPPU_HH
