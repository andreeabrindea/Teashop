#pragma once
#include <exception>
#include <string>

class Exceptions : public std::exception {

public:
    virtual const char* what() const noexcept override {
    return "Exception!";
    };
};

class ProductException : public Exceptions
{
private:
    std::string m_error;

public:
    ProductException(std::string error) {
        m_error = "Product exception caught: " + error;
    }
    const char* what()const noexcept override  { return m_error.c_str(); }
};


class ControllerException: public Exceptions
{
private:
    std::string m_error;

public:
    ControllerException(std::string error) {
        m_error = "Controller exception caught: " + error;
    }
    const char* what() const noexcept override { return m_error.c_str(); }
};


class FileException: public Exceptions
{
private:
    std::string m_error;
    std::string m_file_name;

public:
    FileException(std::string error, std::string file): m_file_name(file) {
        m_error = "File exception caught : " + error + "The file used is: " + m_file_name + "\n\n";
    }
    const char* what() const noexcept override {return m_error.c_str(); }
};

