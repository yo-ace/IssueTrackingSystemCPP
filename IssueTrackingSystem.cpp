/*
 * @author Irmak Imdat
*/
#include "IssueTrackingSystem.h"

IssueTrackingSystem::IssueTrackingSystem()
{
    issues = nullptr;
    employees = nullptr;
    issuesSize = 0;
    employeesSize = 0;
}

IssueTrackingSystem::~IssueTrackingSystem()
{
    if(issues)
    {
        delete[] issues;
    }
    if(employees)
    {
        delete[] employees;
    }
}

void IssueTrackingSystem::addEmployee( const string name, const string title )
{
    if(employeeExists(name))
    {
        // employee exists

        cout << "Cannot add employee. Employee with name " << name << " already exists." << endl;
    }
    else
    {
        //store the prev array in temp pointer, make employees pointer point to a new dinamically
        //allocated array, enter the prev values from temp, add the new employee to last.

        Employee* temp = employees;

        employees = new Employee[employeesSize + 1];

        for(int i = 0; i < employeesSize; i++)
        {
            employees[i] = temp[i];
        }

        employees[employeesSize].setName(name);         //already have an employee object that has garbage values, 
        employees[employeesSize].setTitle(title);       //so set the values to given strings instead of creating a new object
        employeesSize++;

        if(temp) { delete[] temp; }

        cout << "Added employee " << name << "." << endl;
    }
}

void IssueTrackingSystem::removeEmployee( const string name )
{
    if(employeeExists(name))
    {
        int index = findEmployee(name);

        if(employees[index].hasIssues())
        {
            // do not remove employee

            cout << "Cannot remove employee. " << name << " has assigned issues." << endl;
        }
        else
        {
            // remove employee
            // what if employees <= 0 
            if(employeesSize > 1)
            {
                Employee* temp = employees;
                employees = new Employee[employeesSize - 1];

                for(int i = 0; i < index; i++)
                {
                    employees[i] = temp[i];
                }

                for(int i = index + 1; i < employeesSize; i++)
                {
                    employees[i - 1] = temp[i];
                }

                employeesSize--;

                if(temp) { delete[] temp; }
            }
            else
            {
                delete[] employees;
                employees = nullptr;
                employeesSize = 0;
            }
            
            cout << "Removed employee " << name << "." << endl;
        }
    }
    else
    {
        //no employee to be removed

        cout << "Cannot remove employee. There is no employee with name " << name << "." << endl;
    }    
}

void IssueTrackingSystem::addIssue( const int issueId, const string description, const string assigneeName )
{
    if(employeeExists(assigneeName))
    {
        if(issueExists(issueId))
        {
        // do not add issue

        cout << "Cannot add issue. Issue with ID " << issueId << " already exists." << endl; 
        }
        else
        {
            // add issue
            
            Issue* temp = issues;

            if(issuesSize > 0)
            {
                issues = new Issue[issuesSize + 1];

                for(int i = 0; i < issuesSize; i++)
                {
                    issues[i] = temp[i];
                }

                issues[issuesSize].setDescription(description);
                issues[issuesSize].setAssigneeName(assigneeName);
                issues[issuesSize].setID(issueId);
            }
            else
            {
                issues = new Issue[issuesSize + 1];
                issues[issuesSize].setDescription(description);
                issues[issuesSize].setAssigneeName(assigneeName);
                issues[issuesSize].setID(issueId);
            }

            if(temp) 
            { 
                delete[] temp; 
            }
            
            issuesSize++;

            employees[findEmployee(assigneeName)].addIssue(issueId, description, assigneeName);

            cout << "Added issue " << issueId << "." << endl;
        }
    }
    else
    {
        cout << "Cannot add issue. There is no employee with name " << assigneeName << "." << endl;
    }
}

void IssueTrackingSystem::removeIssue( const int issueId )
{
    if(issueExists(issueId))
    {
        int index = -1;

        for(int i = 0; i < issuesSize; i++)
        {
            if(issues[i].getID() == issueId)
            {
                index = i;
            }
        }

        employees[findEmployee(issues[index].getAssigneeName())].removeIssue(issues[index].getID());

        Issue* temp = issues;

        if(issuesSize > 1)
        {
            issues = new Issue[issuesSize - 1];

            for(int i = 0; i < index; i++)
            {
                issues[i] = temp[i];
            }

            for(int i = index + 1; i < issuesSize; i++)
            {
                issues[i - 1] = temp[i];
            }

            issuesSize--;
        }
        else
        {
            issuesSize = 0;
            issues = nullptr;
        }
        
        if(temp) { delete[] temp; }
        
        cout << "Removed issue " << issueId << "." << endl;
    }
    else
    {
        cout << "Cannot remove issue. There is no issue with ID " << issueId << "." << endl;
    }
}

void IssueTrackingSystem::changeAssignee( const string previousAssignee, const string newAssignee )
{
    if(employeeExists(previousAssignee) && employeeExists(newAssignee))
    {
        int indexPrev = findEmployee(previousAssignee);
        int indexNew = findEmployee(newAssignee);

        for(int i = 0; i < employees[indexPrev].getIssuesSize(); i++)
        {
            int issueId = employees[indexPrev].getIssue(i).getID();
            string description = employees[indexPrev].getIssue(i).getDescription();
            
            employees[indexNew].addIssue(issueId, description, employees[indexNew].getName());
            issues[findIssue(issueId)].setAssigneeName(employees[indexNew].getName());
        }

        for(int i = employees[indexPrev].getIssuesSize() - 1; i >= 0; i--)
        {
            employees[indexPrev].removeIssue(employees[indexPrev].getIssue(i).getID());
        }

        cout << previousAssignee << "'s issues are transferred to " << newAssignee << "." << endl;
    }
    else
    {
        cout << "Cannot change assignee. Previous or/and new assignee does not exist." << endl;
    }
}

void IssueTrackingSystem::showAllEmployees() const
{
    cout << "Employees in the system:" << endl;

    if(employeesSize > 0)
    {
        for(int i = 0; i < employeesSize; i++)
        {
            cout << employees[i].getName() << ", " << employees[i].getTitle() << ", " 
            << employees[i].getIssuesSize() << " issue(s)." << endl;
        }
    }
    else
    {
        cout << "None" << endl;
    }
}

void IssueTrackingSystem::showAllIssues() const
{
    cout << "Issues in the system:" << endl;

    if(issuesSize > 0)
    {
        for(int i = 0; i < employeesSize; i++)
        {
            for(int j = 0; j < employees[i].getIssuesSize(); j++)
            {
                cout << employees[i].getIssue(j).getID() << ", " << employees[i].getIssue(j).getDescription() << ", " 
                << employees[i].getIssue(j).getAssigneeName() << "." << endl;
            }
        }
    }
    else
    {
        cout << "None" << endl;
    }
}

void IssueTrackingSystem::showEmployee( const string name ) const
{
    if(employeeExists(name))
    {
        int index = findEmployee(name);

        cout << employees[index].getName() << ", " << employees[index].getTitle() << ", " 
            << employees[index].getIssuesSize() << " issue(s)." << endl;
    }
    else
    {
        cout << "Cannot show employee. There is no employee with name " << name << "." << endl;
    }
}

void IssueTrackingSystem::showIssue( const int issueId ) const
{
    if(issueExists(issueId))
    {
        int index = -1;

        for(int i = 0; i < issuesSize; i++)
        {
            if(issueId == issues[i].getID())
            {
                index = i;
            }
        }

        cout << issues[index].getID() << ", " << issues[index].getDescription() << 
        ", " << issues[index].getAssigneeName() << "." << endl;
    }
    else
    {
        cout << "Cannot show issue. There is no issue with ID " << issueId << "." << endl;
    }
}

bool IssueTrackingSystem::employeeExists(string name) const
{
    bool exist = false;

    for(int i = 0; i < employeesSize && !exist; i++)
    {
        if(employees[i].getName().compare(name) == 0)
        {
            exist = true;
        }
    }

    return exist;    
}

bool IssueTrackingSystem::issueExists(int issueId) const
{
    bool exist = false;

    for(int i = 0; i < issuesSize; i++)
    {
        if(issues[i].getID() == issueId)
        {
            exist = true;
        }
    }

    return exist;
}

int IssueTrackingSystem::findEmployee(string name) const
{
    int index = -1;

    if(employeeExists(name))
    {
        for(int i = 0; i < employeesSize; i++)
        {
            if(employees[i].getName().compare(name) == 0)
            {
                index = i; // found the employee
            }
        }
    }
    return index;   
}

int IssueTrackingSystem::findIssue(int issueId)
{
    int index = -1;

    for(int i = 0; i < issuesSize; i++)
    {
        if(issues[i].getID() == issueId)
            index = i;
    }

    return index;
}