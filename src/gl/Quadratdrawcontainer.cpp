#include "Quadratdrawcontainer.h"

Quadratdrawcontainer::Quadratdrawcontainer(){

}

/*
 *
 *
 */
Quadratdrawer* Quadratdrawcontainer::getdrawer(std::string a_name){
    for(auto it = m_drawers.begin(); it != m_drawers.end(); ++it){
        if( (*it).name == a_name){
            return &(*it);
        }
    }

    m_drawers.push_back(Quadratdrawer(a_name));

    return &m_drawers.back();
}
