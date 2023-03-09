#ifndef __TIME_HPP__
#define __TIME_HPP__

#include <GLFW/glfw3.h>

float deltaTime = 0.0f;
float lastFrame = 0.0f;

namespace Time {

    static float DeltaTime(){
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        return deltaTime;
    }

} //!namespace time
#endif // __TIME_HPP__