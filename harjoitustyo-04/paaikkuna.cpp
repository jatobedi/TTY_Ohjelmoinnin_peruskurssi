// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-04
// Janne Aare 235645
// janne.aare@student.tut.fi

#include <QtWidgets>
#include <QString>
#include "paaikkuna.hh"
#include "ui_paaikkuna.h"

Paaikkuna::Paaikkuna(QWidget *parent) :
    // Rakentaja, joka luo pääikkunan,actionit, menut ja
    // päivittää kentät aloituskuntoon.

    QMainWindow(parent),
    ui(new Ui::Paaikkuna)
{
    ui->setupUi(this);

    luo_actionit();
    luo_menut();
    paivita_kentat();

}

Paaikkuna::~Paaikkuna()
{
    delete ui;
}

void Paaikkuna::luo_actionit(){
    // Luo actionit, action groupin sukupuolille ja
    // yhdistää signalit sloteihin.

    act_alkutila = new QAction(tr("Alkutila"), this);
    connect(act_alkutila,SIGNAL(triggered(bool)),
            this, SLOT(nollaa_kaikki_arvot()));

    act_lopeta = new QAction(tr("Lopeta"), this);
    connect(act_lopeta,SIGNAL(triggered(bool)),
            this, SLOT(close()));

    act_nainen = new QAction(tr("Nainen"), this);
    connect(act_nainen,SIGNAL(triggered(bool)),
            this,SLOT(paivita_kentat()));
    act_nainen->setCheckable(true);

    act_mies = new QAction(tr("Mies"), this);
    connect(act_mies,SIGNAL(triggered(bool)),
            this,SLOT(paivita_kentat()));
    act_mies->setCheckable(true);

    sukupuoliryhma = new QActionGroup(this);
    sukupuoliryhma->addAction(act_nainen);
    sukupuoliryhma->addAction(act_mies);
    act_nainen->setChecked(true);

    connect(ui->spinBox_paino,SIGNAL(valueChanged(int)),
            this, SLOT(paivita_kentat()));

    connect(ui->spinBox_pituus,SIGNAL(valueChanged(int)),
            this, SLOT(paivita_kentat()));
}

void Paaikkuna::luo_menut(){
    // Luo menut ja lisää niihin niiden actionit.

    menu_toimenpide = menuBar()->addMenu(tr("Toimenpide"));
    menu_toimenpide->addAction(act_alkutila);
    menu_toimenpide->addAction(act_lopeta);

    menu_sukupuoli = menuBar()->addMenu(tr("Sukupuoli"));
    menu_sukupuoli->addAction(act_nainen);
    menu_sukupuoli->addAction(act_mies);
}

void Paaikkuna::nollaa_kaikki_arvot(){
    // Asettaa kaikki arvot alkutilaan.

    ui->Slider_paino->setValue(0);
    ui->Slider_pituus->setValue(0);
    act_nainen->setChecked(true);
    paivita_kentat();
}

double Paaikkuna::laske_bmi(double paino, double pituus){
    // Laskee painoindeksin.
    // double paino: laskussa käytettävä paino kiloina.
    // double pituus: laskussa käytettävä paino sentteinä.
    // return double: laskettu painoindeksi kg/m2.

    double pituus_m = pituus / 100;
    if (pituus != 0){
        return paino / (pituus_m * pituus_m);
    }else{
        return 0;
    }
}

void Paaikkuna::paivita_kentat(){
    // Päivittää kenttiin niiden oikeat arvot.

    double bmi = laske_bmi(ui->spinBox_paino->value(),ui->spinBox_pituus->value());
    QString bmi_teksti = QString::number(bmi);

    bool nainen = act_nainen->isChecked();

    if (nainen){
        ui->label_arvo_sukupuoli->setText("nainen");
    }else{
        ui->label_arvo_sukupuoli->setText("mies");
    }

    if (ui->spinBox_paino->value() != 0 and ui->spinBox_pituus->value() != 0){
        ui->label_arvo_painoindeksi->setText(bmi_teksti);
        if (act_nainen->isChecked()){
            tulosta_nais_bmi(bmi);
        }else{
            tulosta_mies_bmi(bmi);
        }
    }else{
        ui->label_arvo_painoindeksi->setText("-");
        ui->label_arvo_tulkinta->setText("-");
    }
}

void Paaikkuna::tulosta_mies_bmi(double bmi){
    // Tulostaa painoindeksin tulkinnan miehelle.
    // double bmi: painoindeksi, josta tulkinta tehdään.

    if ( bmi <= 20.7 ){
        ui->label_arvo_tulkinta->setText("alipainoa");
    }
    else if ( bmi <= 26.4 ){
        ui->label_arvo_tulkinta->setText("normaali");
    }
    else if ( bmi <= 27.8 ){
        ui->label_arvo_tulkinta->setText("lievää ylipainoa");
    }
    else if ( bmi <= 31.1){
        ui->label_arvo_tulkinta->setText("ylipainoa");
    }else{
        ui->label_arvo_tulkinta->setText("paljon ylipainoa");
    }
}

void Paaikkuna::tulosta_nais_bmi(double bmi){
    // Tulostaa painoindeksin tulkinnan naiselle.
    // double bmi: painoindeksi, josta tulkinta tehdään.

    if ( bmi <= 19.1 ){
        ui->label_arvo_tulkinta->setText("alipainoa");
    }
    else if ( bmi <= 25.8 ){
        ui->label_arvo_tulkinta->setText("normaali");
    }
    else if ( bmi <= 27.3 ){
        ui->label_arvo_tulkinta->setText("lievää ylipainoa");
    }
    else if ( bmi <= 32.2){
        ui->label_arvo_tulkinta->setText("ylipainoa");
    }else{
        ui->label_arvo_tulkinta->setText("paljon ylipainoa");
    }
}

