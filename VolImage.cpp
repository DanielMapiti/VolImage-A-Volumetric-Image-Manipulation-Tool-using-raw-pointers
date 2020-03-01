#include <fstream>
#include <sstream>
#include "VolImage.h"
#include <iostream>
#include <ios>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;
unsigned char** bufferImage;
int imageNum=0;

VolImage::VolImage(){
    VolImage::width=0;
    VolImage::height=0;
    VolImage::slices = vector<unsigned char**>(0);
}

bool VolImage::readImages(std::string baseName){
   /** string file = baseName+".data";
    ifstream ifs(file.c_str()); //put binary in
    int imageNum;
    int counter=1;
    string line; getline(ifs, line);
    istringstream iss(line);
    string num;

    if(ifs.is_open()){
        while(getline(iss, num, ' ')){
            istringstream ss(num);
            int i;
            ss>>i;
            if (counter==1){
                VolImage::width = i;
                counter++;
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
**/


    string file = baseName+".data";
    ifstream ifs(file);

    int data[3] = {};
	ostringstream oss;

	if(!ifs){
		cerr << "Unable to open " + baseName;
		exit(1);
	}

	for (int i = 0; i < 3; i++){
		ifs >> data[i];
	}
    VolImage::width = data[0];
    VolImage::height = data[1];
    imageNum = data[2];

    VolImage::slices.resize(imageNum);
    for (int i=0;i<imageNum;i++){
        string rawName = baseName +to_string(i)+".raw";
        ifstream rawfile(rawName,ios::binary);
        VolImage::slices[i]= new unsigned char*[height];

        if(rawfile.is_open()){
            for(int j=0;j<VolImage::height;j++){
                VolImage::slices[i][j] = new unsigned char[width];
                for (int k=0;k<VolImage::width;k++){
                    VolImage::slices[i][j][k]= u_char(rawfile.get());
                }
            }
            rawfile.close();

        }

    }
    return true;
}

void VolImage::diffmap(int sliceI, int sliceJ, string output_prefix){
    ofstream ofs(output_prefix+".raw",ios::binary);

    vector<unsigned char**> v= vector<unsigned char**>(2);
    for(int i=0;i<imageNum;i++){
        if(sliceI==i){
            v[0]=VolImage::slices[i];
        }else if(sliceJ==i){
            v[1]=VolImage::slices[i];
        }
    }
    for(int j=0;j<VolImage::height;j++){
        for(int k=0;k<VolImage::width;k++){
            ofs<< (unsigned char)(abs((float)v[0][j][k]- (float)v[1][j][k])/2);
        }
    }

}

int main(int argc, char* argv[]) throw(){
	
	VolImage volImage;
	
	volImage.readImages(argv[1]);
	
	if(argv[2][1] == 'd'){
		volImage.diffmap(atoi(argv[3]), atoi(argv[4]), argv[5]);
	}
	else{
		cout << "unexpected input" << endl;
		return 1;
	}

	return 0;
}