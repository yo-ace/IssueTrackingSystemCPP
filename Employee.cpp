/**
 * @author Irmak Imdat
*/
#include "Employee.h"

Employee::Employee()
{
    this->name = "";
    this->title = "";
    this->issues = nullptr;
    this->issuesSize = 0;
}

Employee::Employee(const string name, const string title)
{
    this->name = name;
    this->title = title;
    this->issues = nullptr;
    this->issuesSize = 0;
}

Employee::~Employee()
{
    if(issues)
    {
        delete[] issues;
    }
}

string Employee::getName() const
{
    return name;
}

string Employee::getTitle() const
{
    return title;
}

int Employee::getIssuesSize() const
{
    return issuesSize;
}

Issue Employee::getIssue(int index) const
{
    if(index >= 0 || index < issuesSize)
        return issues[index];   
    else
    {
        Issue issue;
        return issue;
    }
}

void Employee::setName(const string name)
{
    this->name = name;
}

void Employee::setTitle(const string title)
{
    this->title = title;
}

void Employee::addIssue(const int issueId, const string description, const string assigneeName)
{
    // check if the issue already exists, if not make temp pointer point to current list
    // make issues point to a new dynamically allocated array with a 
    bool exist = false;

    for(int i = 0; i < issuesSize && !exist; i++)
    {
        if(issueId == issues[i].getID())
        {   
            exist = true;
        }
    }

    if(exist)
    {
        // do not add the issue
        cout << "Employee already has the given issue." << endl;
    }
    else
    {
        //add issue

        Issue* temp = issues;

        issues = new Issue[issuesSize + 1];

        for(int i = 0; i < issuesSize; i++)
        {
            issues[i] = temp[i];
        }

        issues[issuesSize].setDescription(description);
        issues[issuesSize].setAssigneeName(assigneeName);
        issues[issuesSize].setID(issueId);
        issuesSize++;

        if(temp) { delete[] temp; }
    }
}

void Employee::removeIssue(const int issueId)
{
    bool exist = false;

    for(int i = 0; i < issuesSize; i++)
    {
        if(issues[i].getID() == issueId)
        {
            exist = true;
        }
    }

    if(exist)
    {
        int index = -1;

        for(int i = 0; i < issuesSize; i++)
        {
            if(issues[i].getID() == issueId)
            {
                index = i;
            }
        }

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
    }
}

bool Employee::hasIssues()
{
    return (issues != nullptr);
}

Employee& Employee::operator=(const Employee& right)
{
    if(&right != this)
    {
        this->setName(right.getName());
        this->setTitle(right.getTitle());

        if(right.getIssuesSize() != this->getIssuesSize())
        {   
            delete[] this->issues;
            this->issues = new Issue[right.getIssuesSize()];
            this->issuesSize = right.getIssuesSize();
        }
        
        for(int i = 0; i < right.getIssuesSize(); i++)
        {
            this->issues[i] = right.getIssue(i);
        }
    }

    return *this;
}