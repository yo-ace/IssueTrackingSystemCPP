/*
 * @author Irmak Imdat
*/
#include "Issue.h"

Issue::Issue()
{
    this->description = "";
    this->assigneeName = "";
    this->id = 0;
}

Issue::Issue(const string description, const string assigneeName, const int id)
{
    this->description = description;
    this->assigneeName = assigneeName;
    this->id = id;
}

string Issue::getDescription() const
{
    return description;
}

string Issue::getAssigneeName() const
{
    return assigneeName;
}

int Issue::getID() const
{
    return id;
}

void Issue::setDescription(string description)
{
    this->description = description;
}

void Issue::setAssigneeName(string assigneeName)
{
    this->assigneeName = assigneeName;
}

void Issue::setID(int id)
{
    this->id = id;
}

Issue& Issue::operator=( const Issue& right)
{
    if(&right != this)
    {
        setAssigneeName(right.getAssigneeName());
        setDescription(right.getDescription());
        setID(right.getID());
    }

    return *this;
}