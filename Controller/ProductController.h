#include "../Repository/Repository.h"
#include <iostream>
#include <stack>

class ProductController {
private:
    Repository m_repo;
    std::stack <std::pair <Product, int> > undoStack, redoStack;  //1-if we add, 2-if we delete
public:
    explicit ProductController(const Repository &mRepo);
    void addaNewProduct(Product* a);
    void deleteProductById(int id);
    void display();
};

