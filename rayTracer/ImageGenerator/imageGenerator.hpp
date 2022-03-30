//
//  imageGenerator.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef imageGenerator_hpp
#define imageGenerator_hpp

class ImageGenerator {
public:
    virtual int writeNextPixel(int, int, int) = 0;
    virtual int resetCursor() = 0;
};

#endif /* imageGenerator_hpp */
