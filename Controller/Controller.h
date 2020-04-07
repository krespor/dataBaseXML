#ifndef UNTITLED_CONTROLLER_H
#define UNTITLED_CONTROLLER_H

#include "../Model/Model.h"

class Controller
{
private:
    Model model;
public:
    Controller();

    std::vector<Department> getDepartments();
    bool addEmployment(std::string department,
            std::string surname,
            std::string name,
            std::string middleName,
            std::string function,
            std::string salary);

    void addDepartment(std::string name);
    void commit();
};


#endif //UNTITLED_CONTROLLER_H
