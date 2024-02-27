/*
 * @author Irmak Imdat
*/
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Issue.h"

class Employee
{
    public:

        Employee();
        Employee(const string name, const string title);
        ~Employee();
        string getName() const;
        string getTitle() const;
        int getIssuesSize() const;
        Issue getIssue(int) const;
        void setName(const string name);
        void setTitle(const string title);
        void addIssue(const int id, const string description, const string assigneeName);
        void removeIssue(const int issueId);
        bool hasIssues();
        Employee& operator=(const Employee& right);

    private:
        
        string name;
        string title;
        Issue* issues;
        int issuesSize;
};

#endif // EMPLOYEE_H