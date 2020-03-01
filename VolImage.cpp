#include <fstream>
#include <sstream>
#include "VolImage.h"

unsigned char** bufferImage

VolImage(){
    width=0;
    height=0;
    slices = vector<unsigned char**>(0);
}

bool readImages(string baseName){
    string file = baseName+".data"
    ifstream ifs(file.c_str()); //put binary in
    int imageNum;
    int counter=1;
    string line; getline(ifs, line);
    istringstream iss(line);
    string num;

    if(ifs.is_open()){
        while(getline(iss, num, ' ')){
            istreamstring ss(num);
            int i;
            ss>>i;
            if (counter==1){
                width = i;
                counter++
            }
            else if (counter==2){
                height=i;
                counter++;
            }
            else{
                imageNum=i;   
                counter++;         
            }
        }
        
            ifs.close();

    }
    else{cout<<"Couldn't open file!\n"}
    slices.resize(imageNum);
    for (int i=0;i<imageNum;i++){
        string rawName = baseName +boost::lexical_cast<string>(i)+".raw";
        ifstream rawfile(rawName.c_str,binary);
        slices[i]= new unsigned char*[height];

        if(rawfile.is_open){
            for(int j=0,j<height;j++){
                slices[i][j] = new unsigned char[width];
                for (int k=0;k<width;k++){
                    slides[i][j][k]= u_char(rawfile.get())
                }
            }
            rawfile.close();
        }

    }
    return true;
}

void diffmap(int sliceI, int sliceJ, string output_prefix){
    ofstream ofs(output+".raw",binary);

    vector<unsigned char**> v= vector<unsigned char**>(2);
    for(int i=0;i<imageNum<i++){
        if(sliceI==i){
            v[0]=slices[i];
        }else if(sliceJ==i){
            v[1]=slices[i];
        }
    }
    for(int j=0;j<height;j++){
        for(int k=0;k<width,k++){
            ofs<< (u_char)(abs((float)v[0][j][k]- (float)v[1][j][k])/2);
        }
    }

}
