#include <iostream>
#include "VolImage.h"
using namespace std;

int main(int argc, char** argv){
    VolImage vol;
    
    if(argc<2){
        cout<<"Error!\n";
        return 0;
    }

    vol.readImages(argv[1]);

    cout<<"Number of images: "<< vol.num_of_images()<<endl;
    cout<< "Number of bytes required: "<< vol.volImageSize()<<endl;

     if(argc==6){

        if(string(argv[2]).compare("-d")==0){
            vol.diffmap(atoi(argv[3]),atoi(argv[4]),argv[5]);
            cout<<"Done\n";
            cout<< "The difference between the slices is stored in "<<argv[5]<<".raw\n";
        }else{
            cout<<"wrong arguments format\n";
        }
    }

    else if(argc==5){
        if(string(argv[2]).compare("-x")==0){
            vol.extract(stoi(argv[3]),argv[4]);
            cout<<"Done\n";
            cout<< "The image has been extracted to "<< argv[4]<<".raw\n";
        }
        else if(string(argv[2]).compare("-g")==0){
            vol.extractImageRow(stoi(argv[3]), argv[4]);
            cout<<"Done!\n";
            cout<<"The row of all the required slices has been stored to "<<argv[4]<<".raw\n\n";
        }
        else{
            cout<<"wrong arguments format\n";
        }
    }

    else{
            cout<<"wrong arguments format\n";
    }

    return 0;

        

}