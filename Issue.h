/*
 * @author Irmak Imdat
*/
#ifndef ISSUE_H
#define ISSUE_H
#include <iostream>
#include <string>

using namespace std;

class Issue
{
    public:

        Issue();
        Issue(const string description, const string assigneeName, const int id);
        string getDescription() const;
        string getAssigneeName() const;
        int getID() const;
        void setDescription(string description);
        void setAssigneeName(string assigneeName);
        void setID(int id);
        Issue& operator=( const Issue& right);

    private:

        string description;
        string assigneeName;
        int id;
};

#endif // ISSUE_H