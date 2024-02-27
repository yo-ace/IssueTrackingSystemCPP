/*
 * @author Irmak Imdat
*/
#ifndef ISSUETRACKINGSYSTEM_H
#define ISSUETRACKINGSYSTEM_H

#include "Employee.h"

class IssueTrackingSystem
{
    public:
        
        IssueTrackingSystem();

        ~IssueTrackingSystem();

        void addEmployee( const string name, const string title );

        void removeEmployee( const string name );

        void addIssue( const int issueId, const string description, const string assigneeName );

        void removeIssue( const int issueId );

        void changeAssignee( const string previousAssignee, const string newAssignee );

        void showAllEmployees() const;

        void showAllIssues() const;

        void showEmployee( const string name ) const;

        void showIssue( const int issueId ) const;

        bool employeeExists(string name) const;

        bool issueExists(int id) const;

        int findEmployee(string name) const;

        int findIssue(int issueId);

    private: 

        Issue* issues;
        Employee* employees;
        int issuesSize;
        int employeesSize;
};

#endif // ISSUETRACKINGSYSTEM_H