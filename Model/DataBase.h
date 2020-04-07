#ifndef UNTITLED_DATABASE_H
#define UNTITLED_DATABASE_H

#include "IDataBase.h"
#include "../tinyxml2.h"

using namespace tinyxml2;

class DataBase : public IDataBase
{
private:
    XMLDocument doc;

    std::string path;

    bool loadDB();
public:
    DataBase(std::string path);

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


#endif //UNTITLED_DATABASE_H
