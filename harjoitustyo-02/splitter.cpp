#include "splitter.hh"


Splitter::Splitter(const string& paloiteltava_merkkijono):
    paloiteltava_(paloiteltava_merkkijono), kentat_( {} ) {
}

void Splitter::aseta_paloiteltava_merkkijono(const string& merkkijono) {
    paloiteltava_ = merkkijono;
    kentat_ = {};  // kentat.clear();
}

unsigned int Splitter::paloittele(char erotinmerkki, bool ohita_tyhjat) {
    kentat_.clear();
    string::size_type alkukohta = 0;
    string kentan_teksti;
    while ( true ) {
        string::size_type loppukohta;
        loppukohta = paloiteltava_.find(erotinmerkki, alkukohta);
        if ( loppukohta == string::npos ) {
            break;
        }
        kentan_teksti = paloiteltava_.substr(alkukohta, loppukohta - alkukohta);
        if ( not (ohita_tyhjat and kentan_teksti.empty()) ) {
            kentat_.push_back(kentan_teksti);
        }
        alkukohta = loppukohta + 1;
    }
    kentan_teksti = paloiteltava_.substr(alkukohta);

    if ( not (ohita_tyhjat and kentan_teksti.empty()) ) {
        kentat_.push_back(kentan_teksti);
    }
    return kentat_.size();
}

unsigned int Splitter::kenttien_lukumaara() const {
    if ( kentat_.size() == 0 ) {
        return SPLITTER_VIRHE;
    } else {

        return kentat_.size();
    }
}

string Splitter::hae_kentta(unsigned int kentan_numero) const {
    if ( kentat_.empty() or kentan_numero >= kentat_.size() ) {
        throw out_of_range("virheellinen kentan_numero");
    }
    return kentat_.at(kentan_numero);
}
