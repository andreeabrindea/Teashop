
#include "ProductController.h"

ProductController::ProductController(const Repository &mRepo) : m_repo(mRepo) {}

void ProductController::addaNewProduct(Product *a) {
    m_repo.addProduct(a);
//    new Product product;
//    this->undoStack.push({product,1 });  //mark that the operation called was add

}

void ProductController::deleteProductById(int id) {
    m_repo.deleteProduct(id);
}

void ProductController::display() {
    m_repo.returnDatabase();

}
