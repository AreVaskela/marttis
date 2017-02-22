#include "marttis.h"
#include "ui_marttis.h"

marttis::marttis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::marttis)
{
    ui->setupUi(this);
}

marttis::~marttis()
{
    delete ui;
}

void marttis::on_aloitaButton_clicked()
{
    int t = pelaajiaInput.toInt(); //total (git test)
    int krs = kierroksiaInput.toInt();

    if(t<1 || krs<1){ //input-virheiden käsittely
        tulosOutput = "pelaajia " + QString::number(t) + "\n" +
                "kierroksia " + QString::number(krs) + "\n\n" +
                "Pelaajia ja kierroksia pitää olla 1 tai enemmän.";
    }else{
        tulosOutput = "pelaajia " + QString::number(t) + "\n" +
                "kierroksia " + QString::number(krs) + "\n\n";

        int k = 1; //kierros
        bool s = true; //suunta: true eteen, false taakse
        int l = 0; //luku, joka sanottaisi, ellei sanota Martti Suosalo
        int p = 1; //pelaaja vuorossa
        QString sano = ""; //mitä sanotaan

        for(;k<=krs;k++){
            l++;
            sano = QString::number(l);
            if(sano.size()>1){ //suunnanvaihdon tarkastelu, voi vaihtua kun 2+ samaa nroa
                int sum = 0;//summa
                QChar m = '0';//merkki
                bool samoja = false;
                bool eri = false;
                for(int n=0;n<sano.size();n++){
                    sum = sum + sano.at(n).digitValue();
                    (m == sano.at(n)) ? samoja = true : samoja = false; //vierekkäiset samoja
                    if(!samoja && n>0){eri=true;} //yksikin eri, luvut yli 3 nroa
                    m = sano.at(n);
                }
                if(sum==7){sano = "Martti Suosalo";} //lukujen summa 7
                if(samoja && !eri){
                    (s) ? s=false: s=true; //suunnanvaihto
                }
            }//end if(sano
            if(l % 7 == 0){ // jaollinen 7:lla
                sano = "Martti Suosalo";
            }
            if(sano.indexOf("7") != -1){ //yksikin 7 luvussa
                sano = "Martti Suosalo";
            }
            tulosOutput.append(QString::number(k) + ": P: " +
                               QString::number(p) + ": \"" +
                               sano + "\"\n");

            (s) ? p++: p--; //suunnan mukaan seuraava pelaaja
            if(p>t){p=1;}//vuoro ympäri yli
            if(p==0){p=t;} //vuoro ympäri ali

        }//end for(;k
    }
    ui->tulosBrowser->setText(tulosOutput);
}

void marttis::on_pelaajiaInput_textChanged(const QString &arg1)
{
    pelaajiaInput = arg1;
}

void marttis::on_kierroksiaInput_textChanged(const QString &arg1)
{
    kierroksiaInput = arg1;
}
