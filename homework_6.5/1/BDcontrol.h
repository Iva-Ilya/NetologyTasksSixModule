#include <iostream>
#include <pqxx/pqxx>

class BDcontrol{
public:
    BDcontrol(std::string conectionSetup);

    void createTable(std::string tableName);
    void addClient(std::string name, std::string surname, std::string email);
    void addClientPhone(size_t id, std::string phone);
    void changeClientData(size_t id, std::string name, std::string surname, std::string email, std::string phone);
    void removeClientPhone(size_t id);
    void removeClient(size_t id);
    void findClient(std::string name, std::string surname, std::string email, std::string phone);

private:
    pqxx::connection c;
    std::string tableName;
};