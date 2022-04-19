//
//  ppm3.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef ppm3_hpp
#define ppm3_hpp

#include "../imageGenerator.hpp"
#include <fstream>

#define PPM3COMMENT "Yahya Arakil"

enum PPMFileMode { IN_MEMORY, IN_FILE };

class PPM3File : public ImageGenerator{
protected:
    int validationCode;
    int width, height;
    PPMFileMode mode;
    unsigned char* buffer;
    int bufferSize, currentIndex;
    
    static const int version = 3;
    static const int maxRGB = 255;

public:
    int getValidationCode();
    PPM3File() = delete;
    PPM3File(int, int, PPMFileMode);
    ~PPM3File();
    
    virtual int writeToFile(const char*);
    virtual int readFromFile(const char*);
    
    unsigned char& accessBuffer(int, int, int);
    int writeNextPixel(int, int, int) override;
    int writeNextPixel(const Vector3&) override;
    int resetCursor() override;
};

#endif /* ppm3_hpp */
