#ifndef IDMANAGER_H
#define IDMANAGER_H


class IDManager
{
public:
    IDManager();

    long generateID();
private:
    long idCounter;
};

#endif // IDMANAGER_H
