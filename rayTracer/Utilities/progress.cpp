//
//  progress.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 4/1/22.
//

#include "progress.hpp"

Progress::Progress(int total)
: total(total), divider(total/100), current(0), current10(1) {
    std::cout << "\b\b\b" <<"0%" << std::flush;
    this->start = std::chrono::high_resolution_clock::now();
}
    
void Progress::update(){
    if(this->current++ == this->divider && current10 != 100){
        std::cout << "\b\b\b" << current10 <<"%" << std::flush;
        current = 0;
        current10++;
    }
    if(this->current == 0 && this->current10 == 100){
        this->end = std::chrono::high_resolution_clock::now();
        auto minutes = duration_cast<std::chrono::minutes>(this->end - this->start);
        auto seconds = duration_cast<std::chrono::seconds>(this->end - this->start);
        auto mseconds = duration_cast<std::chrono::milliseconds>(this->end - this->start);
        std::cout << "\b\b\bElapsed: "
        << minutes.count() << ":"
        << seconds.count() << ":"
        << mseconds.count()%1000
        << std::endl;
    }
}

