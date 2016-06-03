#include "Systemdrawcontainer.h"

Systemdrawcontainer::Systemdrawcontainer()
{

}

Systemdrawer* Systemdrawcontainer::getdrawer(std::string a_name){
    for(auto it = m_drawers.begin(); it != m_drawers.end(); ++it){
        if( (*it).name == a_name){
            return &(*it);
        }
    }

    m_drawers.push_back(Systemdrawer(a_name));

    return &m_drawers.back();

}
