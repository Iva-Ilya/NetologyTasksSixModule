#include <iostream>
#include <exception>
#include <pqxx/pqxx>

#include "BDcontrol.h"

int main() {
    try {
        std::string connectionSetup{
            "host=localhost "
            "port=5432 "
            "dbname=postgres "
            "user=admin "
            "password=12345"
        };

        BDcontrol bd(connectionSetup);

        bd.createTable("clientsDB");

        bd.addClient("Joe", "Bon", "joe@email.com");
        bd.addClientPhone(1, "12345");

        bd.changeClientData(1, "Joe", "Bon", "joe@email.com", "54321");

        auto clients = bd.findClient("Joe", "", "", "");

        std::cout << "Search results:\n";
        for (const auto& c : clients) {
            std::cout << c.id << " | "
                << c.name << " "
                << c.surname << " | "
                << c.email << " | "
                << c.phone << std::endl;
        }

        bd.removeClientPhone(1);
        bd.removeClient(1);
    }
    catch (const pqxx::sql_error& e) {
        std::cout << "SQL error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}