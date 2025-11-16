#include <iostream>
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

    cout << "\n\nPRODOTTI:";
    for (int i = 0; i<numeroProdottiInput; i++){
        cout << "\n\n";
        cout << "NOME PRODOTTO: " << tabellaProdotti[i].nomeProdotto << "\n";
        cout << "PREZZO DI ACQUISTO: " << tabellaProdotti[i].prezzoDiAcquisto << "\n";
        cout << "PREZZO DI VENDITA: " << tabellaProdotti[i].prezzoDiVendita << "\n";
        cout << "QUANTITA' IN MAGAZZINO: " << tabellaProdotti[i].quantitaInMagazzino << "\n";
        cout << "IVA: " << tabellaProdotti[i].iva << "\n";
        cout << "PREZZO CON IVA: " << tabellaProdotti[i].prezzoConIva << "\n";
        cout << "MARGINE UNITARIO: " << tabellaProdotti[i].margineUnitario << "\n";
        cout << "VALORE TOTALE MAGAZZINO: " << tabellaProdotti[i].valoreTotaleMagazzino << "\n";
        cout << "RIORDINO: ";
        if (tabellaProdotti[i].riordino)
            cout << "SI\n";
        else
            cout << "NO\n";

        totaleMagazzino += tabellaProdotti[i].valoreTotaleMagazzino;
        if (tabellaProdotti[i].riordino)
            prodottiDaRiordinare++;
    }

    char scelta;

    cout << "\n\nVuoi stampare la tabella riassuntiva dei prodotti? Potrebbe non funzionare sul tuo terminale. (s/n)\n";
    cin >> scelta;

    if (scelta == 's' || scelta == 'S'){
        cout << "\n\n";
        cout <<"===================================================================================TABELLA============================================================================================\n";
        cout << "prodotto\tprezzo di acquisto\tprezzo di vendita\tquantita' in magazzino\tIVA\tprezzo con iva\tmargine unitario\tvalore totale stock\triordino\n";

        for (int i = 0; i<numeroProdottiInput; i++){
            cout << tabellaProdotti[i].nomeProdotto << "\t\t";
            cout << tabellaProdotti[i].prezzoDiAcquisto << "\t\t\t";
            cout << tabellaProdotti[i].prezzoDiVendita << "\t\t\t";
            cout << tabellaProdotti[i].quantitaInMagazzino << "\t\t\t";
            cout << tabellaProdotti[i].iva << "\t";
            cout << tabellaProdotti[i].prezzoConIva << "\t\t";
            cout << tabellaProdotti[i].margineUnitario << "\t\t\t";
            cout << tabellaProdotti[i].valoreTotaleMagazzino << "\t\t\t";
            if (tabellaProdotti[i].riordino)
                cout << "SI\n";
            else
                cout << "NO\n";

            totaleMagazzino += tabellaProdotti[i].valoreTotaleMagazzino;
            if (tabellaProdotti[i].riordino)
                prodottiDaRiordinare++;
        }
    
    cout <<"===================================================================================TABELLA============================================================================================\n";
    }

    cout << "\n\n";
    cout <<"==========================================\n";
    cout << "Valore totale del magazzino: " << totaleMagazzino << '\n';
    cout << "Numero di prodotti da riordinare: " << prodottiDaRiordinare << '\n';
    cout <<"==========================================\n";

}
