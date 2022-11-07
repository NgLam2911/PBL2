#ifndef ListAcquaintance_h
#define ListAcquaintance_h
#include "Acquaintance.h"

class ListAcquaintance
{
private:
    Acquaintance *head;
public:
    ListAcquaintance();
    void insertAcquaintance();
    void editAcquaintance(int index);
    void deleteAcquaintance(int index);
    Acquaintance findAcquaintance(string name);
};

#endif