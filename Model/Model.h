#ifndef UNTITLED_MODEL_H
#define UNTITLED_MODEL_H

#include "DataBase.h"

class Model
{
private:
    IDataBase *idb;

public:
    Model();
    //std::vector<Department> getDepartments();
    bool addEmployment(std::string department,
            std::string surname,
            std::string name,
            std::string middleName,
            std::string function,
            std::string salary);

    void addDepartment(std::string name);
    std::vector<Employment> getEmployment(std::string department);
    std::vector<Department> getDepartments();
    void commit();
};


#endif //UNTITLED_MODEL_H
