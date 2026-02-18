#include <iostream>
#include <exception>
#include <pqxx/pqxx>

#include "BDcontrol.h"

int main(){
    try{
        std::string connectionSetup {
            "host=localhost "
            "port=5432 "
            "dbname=postgres "
            "user=admin "
            "password=12345"
        };

        BDcontrol bd(connectionSetup);
        bd.createTable("clinetsDB");
        bd.addClient("Joe", "Bon", "Joe@email.com");
        bd.addClientPhone(1, "12345");
        bd.changeClientData(1, "Joe", "Bon", "Joe@email.com", "54321");
        bd.removeClientPhone(1);
        bd.removeClient(1);
        bd.findClient("Joe", "Bon", "", "");
    }
    catch (pqxx::sql_error e){
        std::cout << e.what() << std::endl;
    }
    catch (std::exception e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}
