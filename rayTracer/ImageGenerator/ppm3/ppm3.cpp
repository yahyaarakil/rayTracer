//
//  ppm3.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "ppm3.hpp"

int PPM3File::getValidationCode(){
    return this->validationCode;
}
PPM3File::PPM3File(int width, int height, PPMFileMode mode)
: width(width), height(height), mode(mode), bufferSize(height * width * 3), currentIndex(0), buffer(new unsigned char[width * height * 3]){}
PPM3File::~PPM3File(){
    delete[] this->buffer;
}

unsigned char& PPM3File::accessBuffer(int j, int i, int c){
    return this->buffer[(i * 3 * this->width) + (j * 3) + c];
}

int PPM3File::writeToFile(const char* filename){
    FILE *filestream = fopen(filename,"w");
    
    fprintf(filestream, "P%d\n", this->version);
    fprintf(filestream, "%d %d\n", this->width, this->height);
    fprintf(filestream, "%d\n", this->maxRGB);
    fprintf(filestream, "#%s\n", PPM3COMMENT);
    
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            for (int c = 0; c < 3; c++) {
                fprintf(filestream, "%d ", this->accessBuffer(j, i, c));
            }
        }
        fprintf(filestream, "\n");
    }
    fclose(filestream);
    return 0;
}
int PPM3File::readFromFile(const char*){
    
    return 0;
}

int PPM3File::writeNextPixel(int r, int g, int b){
    if (this->currentIndex < this->bufferSize) {
        this->buffer[this->currentIndex] = r;
        this->buffer[this->currentIndex + 1] = g;
        this->buffer[this->currentIndex + 2] = b;
        
        this->currentIndex += 3;
        
        return 0;
    }
    return -1;
}
int PPM3File::writeNextPixel(const Vector3& color){
    return this->writeNextPixel(color.x, color.y, color.z);
}

int PPM3File::resetCursor(){
    this->currentIndex = 0;
    return 0;
}
