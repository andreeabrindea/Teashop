#pragma once
#include <algorithm>
#include "Repository.h"
#include <utility>
#include <vector>

int Repository::searchProduct(int id) {
    int it=0;
    while (it != this->m_database.size()){
        if (this->m_database[it]->getId() == id)
            return it;
        it++;
    }
    return it;
}

bool Repository::addProduct(Product* a) {
    if(searchProduct(a->getId()))
        return false;
    m_database.push_back(a);
    return true;
}

Product Repository::deleteProduct(int id) {

    int it = searchProduct(id);
    if (it == this->m_database.size())
        throw std::string("Nonexistent product!");

    Product product= reinterpret_cast<Product &&>(this->m_database[it]);
    this->m_database.erase(this->m_database.begin()+it);
    return product;
}


bool Repository::operator==(const Repository &rhs) const {
    return m_database == rhs.m_database;
}

bool Repository::operator!=(const Repository &rhs) const {
    return !(rhs == *this);
}

void Repository::setMDatabase(const vector<Product *> &mDatabase) {
    m_database = mDatabase;
}

Repository &Repository::operator=(const Repository &other) {
    // Guard self assignment
    if (this == &other)
        return *this;

    std::copy(other.m_database.begin(), other.m_database.end(), this->m_database.begin());
    return *this;
}



