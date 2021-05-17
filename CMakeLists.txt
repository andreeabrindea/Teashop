cmake_minimum_required(VERSION 3.17)
project(Teashopt2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Teashopt2 main.cpp Persistence/Persistence.cpp Persistence/Persistence.h Product.cpp Product.h Tea.cpp Tea.h Accesory.cpp Accesory.h Repository/Repository.cpp Repository/Repository.h Exceptions/Exceptions.h Tests/Tests.h Controller/ProductController.cpp Controller/ProductController.h Utils.h)