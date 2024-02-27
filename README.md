# IssueTrackingSystemCPP
Hi! This repository includes a simple Issue Tracking System implementation for C++. The project represents an example for OOP, while heap usage can also be observed on the implementation. Pointer based data structure is used.

I will be uploading the files in two steps: one will include source files (.h) and one will include implementation files (.cpp). It is a good practice to create files such way, because source files give the necessary utilization information to the user, while protecting the implementation the developer choose not to share.

I should also mention that this is a CS201 (Fundamental Structures of Computer Science) homework given in Bilkent University (İhsan Doğramacı Bilkent University), written by TA Burak Ferit Aktan.

The following are the functionalities of this project:

1. Add a new employee (i.e., a new employee is hired)
2. Remove an employee (i.e., an employee left the company)
3. Create an issue and assign it to an employee
4. Remove an issue
5. Change assignee of all issues of an employee
6. Show the list of all employees
7. Show the list of all issues
8. Show detailed information about an employee
9. Show detailed information about an issue

**Add a new employee**: The issue-tracking system will allow the company to add a new employee
indicating their name and title. The employee names must be unique in the system. Thus, the system
should check whether or not the specified employee already exists, and if they exist, it should not allow
the operation and display a warning message. Initially, an employee is not assigned any issues.
**Remove an employee**: The issue-tracking system will allow the company to remove an existing
employee indicated by their name. If the employee does not exist, the system should not allow the
operation and should display a warning message. If the employee has some assigned issues, the system
should not allow the operation and should display a warning message.
**Create an issue**: The issue-tracking system will be able to create an issue by giving ID number of the
issue, description of the issue, and name of the assignee. Issue IDs are unique, there should be no more
than one issue with the same ID in the system, at the same time. If an issue with the same ID already
exists in the system, the system should not allow the operation and display a warning. Note that an ID
can be reused after its issue is removed.
**Remove an issue**: The issue-tracking system will be able to remove an issue by giving ID number
of the issue. If the issue does not exist, the system should not allow the operation and should display
a warning message. After the issue is removed, its ID number is now available and could be used for a
new issue.
**Change assignee**: The issue-tracking system will allow to move issues from one employee to another.
In this case, all of the issues of the previous assignee will be assigned to the new assignee. As a result,
the number of issues assigned to the previous employee will become zero. If the previous and/or new
assignee names do not exist, the system should not allow the operation and display a warning message.
1
**Show the list of all employees**: The issue-tracking system will allow to display a list of all employees.
The list includes, for each employee, the employee’s name, title, and the number of issues assigned. Note
that the order of employees in the list IS important; you should list in the order they join the company.
**Show the list of all issues**: The issue-tracking system will allow to display of a list of all issues.
The list includes, for each issue, the issue’s ID, description, and name of the assignee. Note that the
order of issues in the list IS important; you should follow the employee order (the order they join the
company), and among issues of the same employee, you should follow the assigning order. Note that,
in change assignee operation, the assigning order is preserved (e.g., if the previous assignee has 2 issues
assigned and new assignee has 5 issues before the change assignee operation, the first issue of the previous
employee will be 6th issue of the new assignee and second issue of previous assignee will be 7th issue of
the new assignee.)
**Show detailed information about an employee**: The issue-tracking system will allow to specify the
name of an employee and display detailed information about that particular employee. This information
includes the employee’s name, title, and number of issues assigned to that employee. If the employee
with that name does not exist, the system should display a warning message.
**Show detailed information about an issue**: The issue-tracking system will allow to specify the ID
of an issue and display detailed information about that particular issue. This information includes the
issue’s ID, description, and name of the assignee. If an issue with that ID does not exist, the system
should display a warning message.
