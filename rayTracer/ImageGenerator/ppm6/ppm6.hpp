//
//  ppm6.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef ppm6_hpp
#define ppm6_hpp

#include "ppm3.hpp"

class PPM6File : public PPM3File {
protected:
    static const int version = 6;
    
public:
    PPM6File() = delete;
    PPM6File(int, int, PPMFileMode);

    int writeToFile(const char*) override;
    int readFromFile(const char*) override;
};

#endif /* ppm6_hpp */
