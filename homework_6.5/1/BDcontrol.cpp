#include "BDcontrol.h"

BDcontrol::BDcontrol(std::string conectionSetup) :
    c{conectionSetup},
    tableName{}
{}

void BDcontrol::createTable(std::string tableName){
    pqxx::work tx( c );
    std::string sqlRequest{"CREATE TABLE IF NOT EXISTS " + 
                            tx.esc(tableName) +
                            " (id SERIAL PRIMARY KEY, name TEXT NOT NULL, surname TEXT NOT NULL, email TEXT, phoneNumber TEXT)"};
    tx.exec(sqlRequest);
    this->tableName = tableName;
    tx.commit();
}


void BDcontrol::addClient(std::string name, std::string surname, std::string email){
    pqxx::work tx( c );
    std::string sqlRequest{"INSERT INTO " + tableName + " (name, surname, email) VALUES('" + 
                            tx.esc(name) + "', '" + 
                            tx.esc(surname) + "', '" +
                            tx.esc(email) + "')"};
    tx.exec(sqlRequest);
    tx.commit();
}


void BDcontrol::addClientPhone(size_t id, std::string phone){
    pqxx::work tx( c );
    std::string sqlRequest{"UPDATE " + tableName + " SET phoneNumber='" + tx.esc(phone) + "' WHERE id=" + tx.quote(id)};
    tx.exec(sqlRequest);
    tx.commit();
}


void BDcontrol::changeClientData(size_t id, std::string name, std::string surname, std::string email, std::string phone){
    pqxx::work tx( c );
    std::string sqlRequest{"UPDATE " + tableName +
                            " SET name = '" + tx.esc(name) + 
                            "', surname = '" + tx.esc(surname) + 
                            "', email='" + tx.esc(email) + 
                            "', phoneNumber='" + tx.esc(phone) + 
                            "' WHERE id=" + tx.quote(id)};
    tx.exec(sqlRequest);
    tx.commit();
}



void BDcontrol::removeClientPhone(size_t id){
    pqxx::work tx( c );
    std::string sqlRequest{"UPDATE " + tableName + " SET phoneNumber=NULL WHERE id=" + tx.quote(id)};
    tx.exec(sqlRequest);
    tx.commit();
}


void BDcontrol::removeClient(size_t id){
    pqxx::work tx( c );
    std::string sqlRequest{"DELETE FROM " + tableName + " WHERE id=" + tx.quote(id)};
    tx.exec(sqlRequest);
    tx.commit();
}


void BDcontrol::findClient(std::string name, std::string surname, std::string email, std::string phone){
    pqxx::work tx( c );
    std::string sqlRequest{"SELECT id, name FROM " + tableName +
                            " WHERE name ILIKE " + tx.quote(name) + 
                            " OR surname ILIKE " + tx.quote(surname) + 
                            " OR email ILIKE " + tx.quote(email) + 
                            " OR phoneNumber ILIKE " + tx.quote(phone)};
    for (auto [id, name] : tx.query<std::string, std::string>(sqlRequest))
    {
        std::cout << id << " - client id and name is " << name << ".\n";
    }
}