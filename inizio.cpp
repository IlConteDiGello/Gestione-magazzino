#include <iostream>
#include <fstream>
#include <string>

#define IVA 0.22

using namespace std;

struct Prodotto {
    string nomeProdotto;
    float prezzoDiAcquisto;
    float prezzoDiVendita;
    int quantitaInMagazzino;
    float iva;
    float prezzoConIva;
    float margineUnitario;
    float valoreTotaleMagazzino;
    bool riordino;
};

int main(){

    int numeroProdottiInput;

    cout << "Quanti prodotti vuoi inserire?\n";
    cin >> numeroProdottiInput;
    Prodotto tabellaProdotti[numeroProdottiInput];

    for (int i = 0; i<numeroProdottiInput; i++){

        string nomeProdotto;
        int prezzoDiAcquisto;
        int prezzoDiVendita;
        int quantitaInMagazzino;

        cout << "\n\n";
        cout << "Inserisci i dati del prodotto " << i+1 << ":\n";
        cout << "Inserisci il nome del prodotto:\n";
        cin >> nomeProdotto;
        cout << "Inserisci il prezzo di acquisto:\n";
        cin >> prezzoDiAcquisto;
        cout << "Inserisci il prezzo di vendita:\n";
        cin >> prezzoDiVendita;
        cout << "Inserisci la quantità in magazzino:\n";
        cin >> quantitaInMagazzino;

        tabellaProdotti[i].nomeProdotto = nomeProdotto;
        tabellaProdotti[i].prezzoDiAcquisto = prezzoDiAcquisto;
        tabellaProdotti[i].prezzoDiVendita = prezzoDiVendita;
        tabellaProdotti[i].quantitaInMagazzino =quantitaInMagazzino;
        tabellaProdotti[i].iva = prezzoDiVendita * IVA;
        tabellaProdotti[i].prezzoConIva = tabellaProdotti[i].iva + prezzoDiVendita;
        tabellaProdotti[i].margineUnitario = prezzoDiVendita - prezzoDiAcquisto;
        tabellaProdotti[i].valoreTotaleMagazzino = quantitaInMagazzino * prezzoDiAcquisto;
        tabellaProdotti[i].riordino = (quantitaInMagazzino < 5);
    }

    float totaleMagazzino = 0;
    int prodottiDaRiordinare = 0;

    for (int i = 0; i<numeroProdottiInput; i++){
        cout << tabellaProdotti[i].nomeProdotto << '\t';
        cout << tabellaProdotti[i].prezzoDiAcquisto << '\t';
        cout << tabellaProdotti[i].prezzoDiVendita << '\t';
        cout << tabellaProdotti[i].quantitaInMagazzino << '\t';
        cout << tabellaProdotti[i].iva << '\t';
        cout << tabellaProdotti[i].prezzoConIva << '\t';
        cout << tabellaProdotti[i].margineUnitario << '\t';
        cout << tabellaProdotti[i].valoreTotaleMagazzino << '\t';
        cout << tabellaProdotti[i].riordino << '\n';

        totaleMagazzino += tabellaProdotti[i].valoreTotaleMagazzino;
        if (tabellaProdotti[i].riordino)
            prodottiDaRiordinare++;
    }

    cout << "Valore totale del magazzino: " << totaleMagazzino << '\n';
    cout << "Numero di prodotti da riordinare: " << prodottiDaRiordinare << '\n';


}
