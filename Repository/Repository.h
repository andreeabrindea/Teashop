#pragma once
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "../Product.h"


class Repository {
private:
    std::vector<Product*> m_database;

    //DESCRIPTION: Searches for a product in the database
    int searchProduct(int id);

public:

    //DESCRIPTION: Adds a new product to the database
    bool addProduct(Product* p);

    //Deletes a product from the database
    Product deleteProduct(int id);

    //DESCRIPTION: Returns the database
    vector<Product *> returnDatabase() { return this->m_database; }

    //DESCRIPTION: Set the database
    void setMDatabase(const vector<Product *> &mDatabase);

    bool operator==(const Repository &rhs) const;
    bool operator!=(const Repository &rhs) const;
    Repository& operator=(const Repository&);
};

