#include "paaikkuna.hh"
#include "ui_paaikkuna.h"

Paaikkuna::Paaikkuna(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Paaikkuna)
{
    ui->setupUi(this);

    connect(ui->button_nollaa, SIGNAL(clicked()),
            this, SLOT(nollaa_kaikki_arvot()));

    connect(ui->mittari_km_h, SIGNAL(valueChanged(int)),
            this, SLOT(aseta_mailit()));
}

Paaikkuna::~Paaikkuna()
{
    delete ui;
}

void Paaikkuna::nollaa_kaikki_arvot() {
          ui->mittari_km_h->setValue(0);
          ui->liukuri_km_h->setValue(0);
          ui->mittari_mailia_h->display(0.0);
      }

void Paaikkuna::aseta_mailit(){
    int km = ui->mittari_km_h->value();
    double mailit = km * 0.62137;
    ui->mittari_mailia_h->display(mailit);
}
