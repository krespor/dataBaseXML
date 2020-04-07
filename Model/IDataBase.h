#ifndef UNTITLED_IDATABASE_H
#define UNTITLED_IDATABASE_H

#include <vector>
#include <iostream>

struct Employment
{
    std::string fullName;
    std::string function;
    uint32_t salary;
};

struct Department
{
    std::string name;
    std::vector<Employment> employments;
    uint32_t countEmployments;
    uint32_t avgSalary;
};

class IDataBase
{
public:
    virtual std::vector<Department> getDepartment() = 0;
    virtual bool addEmployment(std::string department,
            std::string surname,
            std::string name,
            std::string middleName,
            std::string function,
            std::string salary) = 0;

    virtual void addDepartment(std::string name) = 0;

    virtual void commit() = 0;
};


#endif //UNTITLED_IDATABASE_H
