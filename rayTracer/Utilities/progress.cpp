//
//  progress.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 4/1/22.
//

#include "progress.hpp"

//int total = this->scene.camera.height * this->scene.camera.width;
//int div = total / 10;
//int current = 0, current10 = 1;
//float percentage;

Progress::Progress(int total)
: total(total), divider(total/10), current(0), current10(1){
    std::cout << "\b\b\b"<< 0 <<"%";
}
    
void Progress::update(){
    if(this->current == this->divider){
        float percentage = current*(current10++)*100/(total-1);
        current = 0;
        std::cout << "\b\b\b"<<percentage <<"%";
    }
    if(this->current++ == this->divider-1 && this->current10 == 10)
        std::cout << "100%";
}

