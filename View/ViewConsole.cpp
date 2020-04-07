#include "ViewConsole.h"

ViewConsole::ViewConsole()
{
    //dialog();
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
    for (auto &d : controller.getDepartments())
    {
        cout << d.name << endl;
        for (auto &e : controller.getEmployment(d.name))
        {
            cout << "L_" << e.fullName << endl;
            cout << "| L_" << e.function << endl;
            cout << "| L_" << e.salary << endl;
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
