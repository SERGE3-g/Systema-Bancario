/*Creare le classi principali
Le classi principali del sistema bancario sono la classe Banca, la classe Cliente e la classe Conto.
La classe Banca rappresenta la banca stessa, mentre la classe Cliente rappresenta un cliente della banca e
la classe Conto rappresenta il conto bancario del cliente.*/
#include <iostream>
#include <string>

using namespace std;

class Banca
{
private:
    string nome;
    string indirizzo;
    string telefono;

public:
    Banca(string nome, string indirizzo, string telefono)
    {
        this->nome = nome;
        this->indirizzo = indirizzo;
        this->telefono = telefono;
    }
    string getNome()
    {
        return nome;
    }
    string getIndirizzo()
    {
        return indirizzo;
    }
    string getTelefono()
    {
        return telefono;
    }
    void setNome(string nome)
    {
        this->nome = nome;
    }
    void setIndirizzo(string indirizzo)
    {
        this->indirizzo = indirizzo;
    }
    void setTelefono(string telefono)
    {
        this->telefono = telefono;
    }
};

class Cliente
{
private:
    string nome;
    string cognome;
    string indirizzo;
    string telefono;

public:
    Cliente(string nome, string cognome, string indirizzo, string telefono)
    {
        this->nome = nome;
        this->cognome = cognome;
        this->indirizzo = indirizzo;
        this->telefono = telefono;
    }
    string getNome()
    {
        return nome;
    }
    string getCognome()
    {
        return cognome;
    }
    string getIndirizzo()
    {
        return indirizzo;
    }
    string getTelefono()
    {
        return telefono;
    }
    void setNome(string nome)
    {
        this->nome = nome;
    }
    void setCognome(string cognome)
    {
        this->cognome = cognome;
    }
    void setIndirizzo(string indirizzo)
    {
        this->indirizzo = indirizzo;
    }
    void setTelefono(string telefono)
    {
        this->telefono = telefono;
    }
};

class Conto
{
private:
    int numeroConto;
    double saldo;
    Cliente *proprietario;

public:
    Conto(int numeroConto, double saldo, Cliente *proprietario)
    {
        this->numeroConto = numeroConto;
        this->saldo = saldo;
        this->proprietario = proprietario;
    }

    int getNumeroConto()
    {
        return numeroConto;
    }

    void deposita(double importo)
    {
        saldo += importo;
    }

    void preleva(double importo)
    {
        if (saldo < importo)
        {
            throw "Saldo insufficiente";
        }
        saldo -= importo;
    }

    double getSaldo()
    {
        return saldo;
    }

    Cliente *getProprietario()
    {
        return proprietario;
    }
};

class eccezione
{
private:
    string messaggio;

public:
    eccezione(string messaggio)
    {
        this->messaggio = messaggio;
    }
    string getMessaggio()
    {
        return messaggio;
    }
};

class prelievo
{
private:
    double importo;

public:
    prelievo(double importo)
    {
        this->importo = importo;
    }
    double getImporto()
    {
        return importo;
    }
};

int main()
{
    Cliente *cliente1 = new Cliente("Franca", "Francesca", "Via Roma 1", "1234567890");
    Conto *conto1 = new Conto(1, 1000, cliente1);
    conto1->deposita(500);
    conto1->preleva(200);
    cout << "Saldo conto: " << conto1->getSaldo() << endl;
    cout << "=========================================" << endl;

    Cliente *cliente2 = new Cliente("Serge", "Guea", "Via virgilio 19", "0987654321");
    Conto *conto2 = new Conto(2, 2000, cliente2);
    conto2->deposita(10000);
    conto2->preleva(1000);
    cout << "Saldo conto: " << conto2->getSaldo() << endl;
    cout << "=========================================" << endl;

    Cliente *cliente3 = new Cliente("Moussa", "Bamba", "Via virgilio 3", "1234567890");
    Conto *conto3 = new Conto(3, 3000, cliente3);
    conto3->deposita(5000);
    conto3->preleva(1000);
    cout << "Saldo conto: " << conto3->getSaldo() << endl;
    cout << "=========================================" << endl;

    return 0;
}