#include "DataBase.h"

DataBase::DataBase(std::string path)
{
    this->path = path;
    if (loadDB())
    {

    }
}

bool DataBase::loadDB()
{
    XMLError eResult = doc.LoadFile(path.c_str());

    if (eResult != XML_SUCCESS)
    {
        std::cout << "ERROR: file not load" << std::endl;
        return false;
    }

    return true;
}

bool DataBase::addEmployment(std::string department, std::string surname,
        std::string name, std::string middleName,
        std::string function, std::string salary)
{
    XMLElement* root = doc.FirstChildElement("departments");
    XMLNode *departmentNode = root->FirstChild();

    while (true)
    {
        if (departmentNode == nullptr)
        {
            return 0;
        } else if (departmentNode->ToElement()->Attribute("name") == department)
        {

            XMLNode *employmentNode = departmentNode->FirstChild();
            XMLElement *newEmployment = doc.NewElement("employment");
            employmentNode->InsertEndChild(newEmployment);

            XMLElement *newSurname = doc.NewElement("surname");
            XMLElement *newName = doc.NewElement("name");
            XMLElement *newMiddleName = doc.NewElement("middleName");
            XMLElement *newFunction = doc.NewElement("function");
            XMLElement *newSalary = doc.NewElement("salary");

            newSurname->SetText(surname.c_str());
            newName->SetText(name.c_str());
            newMiddleName->SetText(middleName.c_str());
            newFunction->SetText(function.c_str());
            newSalary->SetText(salary.c_str());

            newEmployment->InsertEndChild(newSurname);
            newEmployment->InsertEndChild(newName);
            newEmployment->InsertEndChild(newMiddleName);
            newEmployment->InsertEndChild(newFunction);
            newEmployment->InsertEndChild(newSalary);


            return 1;
        }
        departmentNode = departmentNode->NextSibling();
    }
}

void DataBase::commit()
{
    doc.SaveFile("C:\\Users\\1\\Desktop\\test1.xml");
}

void DataBase::addDepartment(std::string name)
{
    XMLElement* root = doc.FirstChildElement("departments");

    XMLElement *newDepartment = doc.NewElement("department");

    newDepartment->SetAttribute("name", name.c_str());
    newDepartment->InsertEndChild(doc.NewElement("employments"));

    root->InsertEndChild(newDepartment);
}

std::vector<Employment> DataBase::getEmployment(std::string department)
{
    XMLElement* root = doc.FirstChildElement("departments");
    XMLNode *departmentNode = root->FirstChild();

    std::vector<Employment> listEmpl;

    while (departmentNode != nullptr)
    {
        if (departmentNode->ToElement()->Attribute("name") == department)
        {
            XMLNode *employmentNode = departmentNode->FirstChild();
            employmentNode = employmentNode->FirstChild();

            while (employmentNode != nullptr)
            {
                Employment empl;

                XMLNode *surname = employmentNode->FirstChild();
                XMLNode *name = surname->NextSibling();
                XMLNode *middleName = name->NextSibling();
                XMLNode *function = middleName->NextSibling();
                XMLNode *salary = function->NextSibling();

                empl.fullName = surname->ToElement()->GetText();
                empl.fullName += " ";
                empl.fullName += name->ToElement()->GetText();
                empl.fullName += " ";
                empl.fullName += middleName->ToElement()->GetText();

                empl.function = function->ToElement()->GetText();
                std::string strSalary(salary->ToElement()->GetText());
                empl.salary = std::stoi(strSalary);

                listEmpl.push_back(empl);

                employmentNode = employmentNode->NextSibling();
            }
            break;
        }
        departmentNode = departmentNode->NextSibling();
    }

    return listEmpl;
}

std::vector<Department> DataBase::getDepartments()
{
    std::vector<Department> listDep;

    XMLElement* root = doc.FirstChildElement("departments");
    XMLNode *departmentNode = root->FirstChild();

    while (departmentNode != nullptr)
    {
        Department dep;
        dep.name = departmentNode->ToElement()->Attribute("name");
        listDep.push_back(dep);
        departmentNode = departmentNode->NextSibling();
    }

    return listDep;
}
