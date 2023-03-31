#include <iostream>
#include <mysqlx/xdevapi.h>

int main(int argc, char *argv[])
{

   // Creo una connessione al database MySQL
   mysqlx::Session session("localhost", 3306, "root", "Gueaserge");

   // Creare la tabella "conti"
   mysqlx::Schema db = session.getSchema("SistemaBancario");
   mysqlx::Table conti = db.createTable("conti")
                             .addColumn("id", mysqlx::Datatype::INT)
                             .addColumn("numero_conto", mysqlx::Datatype::INT)
                             .addColumn("saldo", mysqlx::Datatype::DOUBLE)
                             .addColumn("cliente", mysqlx::Datatype::VARCHAR)
                             .setPrimaryKey("id")
                             .execute();

   // Creare la tabella "cliente"
   mysqlx::Schema db = session.getSchema("SistemaBancario");
   mysqlx::Table cliente = db.createTable("cliente")
                               .addColumn("id", mysqlx::Datatype::INT)
                               .addColumn("nome", mysqlx::Datatype::VARCHAR)
                               .addColumn("cognome", mysqlx::Datatype::VARCHAR)
                               .addColumn("indirizzo", mysqlx::Datatype::VARCHAR)
                               .addColumn("telefono", mysqlx::Datatype::VARCHAR)
                               .setPrimaryKey("id")
                               .execute();

   // Creare la tabella "banca"
   mysqlx::Schema db = session.getSchema("SistemaBancario");
   mysqlx::Table banca = db.createTable("banca")
                             .addColumn("id", mysqlx::Datatype::INT)
                             .addColumn("nome", mysqlx::Datatype::VARCHAR)
                             .addColumn("indirizzo", mysqlx::Datatype::VARCHAR)
                             .addColumn("telefono", mysqlx::Datatype::VARCHAR)
                             .setPrimaryKey("id")
                             .execute();

   // Chiudere la connessione al database MySQL
   session.close();

   return 0;
}
