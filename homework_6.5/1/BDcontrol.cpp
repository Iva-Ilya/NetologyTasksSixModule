#include "BDcontrol.h"

BDcontrol::BDcontrol(const std::string& connectionSetup)
    : c{ connectionSetup }, tableName{} {}


void BDcontrol::createTable(const std::string& tableName) {
    pqxx::work tx(c);

    std::string sql =
        "CREATE TABLE IF NOT EXISTS " + tableName +
        " ("
        "id SERIAL PRIMARY KEY, "
        "name TEXT NOT NULL, "
        "surname TEXT NOT NULL, "
        "email TEXT, "
        "phoneNumber TEXT"
        ")";

    tx.exec(sql);
    tx.commit();

    this->tableName = tableName;
}


void BDcontrol::addClient(const std::string& name,
    const std::string& surname,
    const std::string& email) {
    pqxx::work tx(c);

    std::string sql =
        "INSERT INTO " + tableName +
        " (name, surname, email) VALUES (" +
        tx.quote(name) + ", " +
        tx.quote(surname) + ", " +
        tx.quote(email) + ")";

    tx.exec(sql);
    tx.commit();
}


void BDcontrol::addClientPhone(size_t id, const std::string& phone) {
    pqxx::work tx(c);

    std::string sql =
        "UPDATE " + tableName +
        " SET phoneNumber = " + tx.quote(phone) +
        " WHERE id = " + tx.quote(id);

    tx.exec(sql);
    tx.commit();
}


void BDcontrol::changeClientData(size_t id,
    const std::string& name,
    const std::string& surname,
    const std::string& email,
    const std::string& phone) {
    pqxx::work tx(c);

    std::string sql =
        "UPDATE " + tableName +
        " SET name = " + tx.quote(name) +
        ", surname = " + tx.quote(surname) +
        ", email = " + tx.quote(email) +
        ", phoneNumber = " + tx.quote(phone) +
        " WHERE id = " + tx.quote(id);

    tx.exec(sql);
    tx.commit();
}


void BDcontrol::removeClientPhone(size_t id) {
    pqxx::work tx(c);

    std::string sql =
        "UPDATE " + tableName +
        " SET phoneNumber = NULL WHERE id = " + tx.quote(id);

    tx.exec(sql);
    tx.commit();
}


void BDcontrol::removeClient(size_t id) {
    pqxx::work tx(c);

    std::string sql =
        "DELETE FROM " + tableName +
        " WHERE id = " + tx.quote(id);

    tx.exec(sql);
    tx.commit();
}


std::vector<Client> BDcontrol::findClient(const std::string& name,
    const std::string& surname,
    const std::string& email,
    const std::string& phone) {
    pqxx::work tx(c);

    std::string sql =
        "SELECT id, name, surname, email, phoneNumber FROM " + tableName +
        " WHERE name ILIKE " + tx.quote("%" + name + "%") +
        " OR surname ILIKE " + tx.quote("%" + surname + "%") +
        " OR email ILIKE " + tx.quote("%" + email + "%") +
        " OR phoneNumber ILIKE " + tx.quote("%" + phone + "%");

    std::vector<Client> result;

    pqxx::result r = tx.exec(sql);

    for (const auto& row : r) {
        Client c;

        c.id = row["id"].as<size_t>();
        c.name = row["name"].as<std::string>();
        c.surname = row["surname"].as<std::string>();

        c.email = row["email"].is_null() ? "" : row["email"].as<std::string>();
        c.phone = row["phonenumber"].is_null() ? "" : row["phonenumber"].as<std::string>();

        result.push_back(c);
    }

    return result;
}