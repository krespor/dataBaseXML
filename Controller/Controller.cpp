#include "Controller.h"

Controller::Controller()
{

}

std::vector<Department> Controller::getDepartments()
{
    return model.getDepartments();
}

bool Controller::addEmployment(std::string department, std::string surname,
        std::string name, std::string middleName,
        std::string function, std::string salary)
{
    return model.addEmployment(department, surname, name, middleName, function, salary);
}

void Controller::commit()
{
    model.commit();
}

void Controller::addDepartment(std::string name)
{
    model.addDepartment(name);
}
