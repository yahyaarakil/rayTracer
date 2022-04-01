//
//  progress.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 4/1/22.
//

#ifndef progress_hpp
#define progress_hpp

#include <iostream>

class Progress{
private:
    int total, divider, current, current10;
    
public:
    Progress() = delete;
    Progress(int);
    
    void update();
};
#endif /* progress_hpp */
