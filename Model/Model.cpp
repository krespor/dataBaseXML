#include "Model.h"

Model::Model()
{
    idb = new DataBase("C:\\Users\\1\\Desktop\\test.xml");
}

std::vector<Department> Model::getDepartments()
{
    return idb->getDepartment();
}

bool Model::addEmployment(std::string department, std::string surname,
        std::string name, std::string middleName,
        std::string function, std::string salary)
{
    return idb->addEmployment(department, surname, name, middleName, function, salary);
}

void Model::commit()
{
    idb->commit();
}

void Model::addDepartment(std::string name)
{
    idb->addDepartment(name);
}
