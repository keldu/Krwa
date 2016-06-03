#include "loader.h"

#include <string>
#include <fstream>
#include <vector>

void LoadObjectMesh(Mesh& mesh, std::string path){

    std::ifstream Objectfilestream(path, std::ios::in);
    if(Objectfilestream.is_open()){
        std::string Line = "";
        while(getline(Objectfilestream, Line)){
            ;
        }

        Objectfilestream.close();
    }else{
        printf("Impossible to open %s. Are you in the right directory ? !\n", path);
        //getchar();
    }

}
