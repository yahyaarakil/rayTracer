//
//  progress.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 4/1/22.
//

#ifndef progress_hpp
#define progress_hpp

#include <iostream>
#include <chrono>
#include <cmath>

class Progress{
private:
    int total, divider, current, current10;
    std::chrono::high_resolution_clock::time_point start, end;
    
public:
    Progress() = delete;
    Progress(int);
    
    void update();
};
#endif /* progress_hpp */
