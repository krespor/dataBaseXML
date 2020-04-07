#include "ViewConsole.h"

ViewConsole::ViewConsole()
{
    dialog();
    //controller.addDepartment("!!TEST!!");
    //controller.addEmployment("!!TEST!!", "1surname1", "2name2", "2middleName2", "3function3", "999");
    //controller.addEmployment("!!TEST!!", "83974", "888q2", "sdkhf", "888", "000");
    //controller.commit();
    /*if (controller.addEmployment("!!TEST!!", "1surname1", "2name2", "2middleName2", "3function3", "999"))
    {
        //showData();
        controller.commit();
    }*/

}

void ViewConsole::dialog()
{
    char response;
    do
    {
        cout << "[1] - to show data" << endl;
        cout << "[2] - to add data" << endl;
        cout << "[3] - to delete data" << endl;
        cout << "[4] - to edit data" << endl;
        cout << "[5] - clear console" << endl;
        cout << "[6] - save" << endl;
        cout << "[q] - to exit" << endl;

        cout << "Enter:";
        cin >> response;

        switch (response)
        {
            case '1':
                showData();
                break;

            case '2':
                addData();
                break;

            case '3':
                deleteData();
                break;

            case '4':
                editData();
                break;

            case '5':
                system("cls");
                break;

            case '6':
                controller.commit();
                break;

            case 'q':
                break;

            default:
                cout << "ERROR" << endl;
        }

    } while (response != 'q');
}

void ViewConsole::showData()
{
    std::vector<Department> departments = controller.getDepartments();

    for (auto &dep: departments)
    {
        cout << dep.name << endl;
        for (auto &empl: dep.employments)
        {
            cout << "L_" << empl.fullName << endl;
            cout << "| L_" << empl.function << endl;
            cout << "| L_" << empl.salary << endl;
        }
    }
}

void ViewConsole::addData()
{
    cout << "[1] - employment" << endl << "[2] - department" << endl << "Enter:";
    char response;
    cin >> response;

    if (response == '1')
    {
        string department, surname, name, middleName, function, salary;
        cout << "department:";
        cin >> department;

        cout << "surname:";
        cin >> surname;

        cout << "name:";
        cin >> name;

        cout << "middleName:";
        cin >> middleName;

        cout << "function:";
        cin >> function;

        cout << "salary:";
        cin >> salary;

        controller.addEmployment(department, surname, name, middleName, function, salary);
    } else if (response == '2')
    {
        string name;
        cout << "name:";
        cin >> name;
        controller.addDepartment(name);
    } else
    {
        cout << "ERROR" << endl;
    }

}

void ViewConsole::deleteData()
{

}

void ViewConsole::editData()
{

}
