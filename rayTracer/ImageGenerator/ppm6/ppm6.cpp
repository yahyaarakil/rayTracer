//
//  ppm6.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "ppm6.hpp"

PPM6File::PPM6File(int width, int height, PPMFileMode mode)
: PPM3File(width, height, mode) {}

int PPM6File::writeToFile(const char* filename){
    FILE *filestream = fopen(filename,"wb");
    
    fprintf(filestream, "P%d\n", this->version);
    fprintf(filestream, "%d %d\n", this->width, this->height);
    fprintf(filestream, "%d\n", this->maxRGB);
    fprintf(filestream, "#%s\n", PPM3COMMENT);
    
    fwrite(this->buffer, sizeof(unsigned char), this->bufferSize, filestream);
    fclose(filestream);
    return 0;
}
int PPM6File::readFromFile(const char*){
    return 0;
}
