#include "idmanager.h"

IDManager::IDManager(): idCounter(1)
{

}

long IDManager::generateID(){
    return idCounter++;
}
