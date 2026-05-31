#pragma once

#include <string>
#include <vector>
#include <pqxx/pqxx>

struct Client {
    size_t id;
    std::string name;
    std::string surname;
    std::string email;
    std::string phone;
};

class BDcontrol {
public:
    BDcontrol(const std::string& connectionSetup);

    void createTable(const std::string& tableName);
    void addClient(const std::string& name, const std::string& surname, const std::string& email);
    void addClientPhone(size_t id, const std::string& phone);
    void changeClientData(size_t id, const std::string& name, const std::string& surname,
        const std::string& email, const std::string& phone);
    void removeClientPhone(size_t id);
    void removeClient(size_t id);

    std::vector<Client> findClient(const std::string& name,
        const std::string& surname,
        const std::string& email,
        const std::string& phone);

private:
    pqxx::connection c;
    std::string tableName;
};