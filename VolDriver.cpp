#include <iostream>
#include "VolImage.h"
using namespace std;

int main(int argc, char** argv){
    VolImage vol;
    vol.readImages(argv[1]);

    if(argc==6){
        if(string(argv[2]).compare("-d")==0){
            istringstream isa(argv[3])>>int a;
            istringstream iab(argv[4])>>int b;
            vol.diffmap(a,b,argv[5]);
            cout<<"Done\n";
        }else{
            cout<<"wrong arguments format\n";
        }
    }

    else if(argc==5){
        if(string(argv[2]).compare("-x")==0){
            istringstream isa(argv[3])>>int a;
            vol.extract(a,argv[4]);
            cout<<"Done\n";
        }
     /**   else if(string(argv[2].compare("-g"))==0){
            istringstream isa(argv[3])>>int a;
        }**/
        else{
            cout<<"wrong arguments format\n";
        }
    }

    else{
            cout<<"wrong arguments format\n";
    }

    return 0;

        

}