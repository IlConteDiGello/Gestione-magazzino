#include <iostream>
#include <fstream>
#include <string>

#define IVA 0.22

using namespace std;

struct Prodotto {
    string nomeProdotto;
    int prezzoDiAcquisto;
    int prezzoDiVendita;
    int quantitaInMagazzino;
    int iva;
    int prezzoConIva;
    int margineUnitario;
    int valoreTotaleMagazzino;
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
}
