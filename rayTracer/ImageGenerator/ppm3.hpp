//
//  ppm3.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef ppm3_hpp
#define ppm3_hpp

#include "imageGenerator.hpp"
#include <fstream>

#define PPM3COMMENT "Yahya Arakil"

enum PPM3FileMode { IN_MEMORY, IN_FILE };

class PPM3File : public ImageGenerator{
private:
    int validationCode;
    int width, height;
    PPM3FileMode mode;
    unsigned char* buffer;
    int bufferSize, currentIndex;
    
    static const int version = 3;
    static const int maxRGB = 255;
    
public:
    int getValidationCode();
    PPM3File() = delete;
    PPM3File(int, int, PPM3FileMode);
    ~PPM3File();
    
    int writeToFile(const char*);
    int readFromFile(const char*);
    
    unsigned char& accessBuffer(int, int, int);
    int writeNextPixel(int, int, int) override;
    int resetCursor() override;
};

#endif /* ppm3_hpp */
