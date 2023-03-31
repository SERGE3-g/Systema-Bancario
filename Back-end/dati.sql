-- Active: 1679926215349@@localhost@3306@Systema Bancario

CREATE TABLE
    Banca(
        id_banca INT PRIMARY KEY NOT NULL,
        /* chiave primaria*/
        nome_banca VARCHAR(50) NOT NULL,
        indirizzo_banca VARCHAR(50) NOT NULL,
        telefono_banca VARCHAR(50) NOT NULL
    );

CREATE TABLE
    Cliente(
        id_cliente INT PRIMARY KEY NOT NULL,
        nome_cliente VARCHAR(50) NOT NULL,
        cognome_cliente VARCHAR(50) NOT NULL,
        indirizzo_cliente VARCHAR(50) NOT NULL,
        telefono_cliente VARCHAR(50) NOT NULL,
        email_cliente VARCHAR(50) NOT NULL
    );

CREATE TABLE
    Conti(
        id_conto INT PRIMARY KEY NOT NULL,
        /*chiave primaria*/
        numero_conto VARCHAR(50) NOT NULL,
        saldo DOUBLE NOT NULL,
        id_cliente INT NOT NULL,
        id_banca INT NOT NULL,
        FOREIGN KEY (id_cliente) REFERENCES Cliente(id_cliente),
        FOREIGN KEY (id_banca) REFERENCES Banca(id_banca)
        /*chiave esterna*/
    );