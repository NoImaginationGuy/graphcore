//
// => example/main.cpp
//
//                                 GraphCore
//
// Copyright (c) 2018 Lorenzo Laneve
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gcore/window/window.h>
#include "graphcore.h"

int glfw_main(int argc, const char *argv[]) {
    
    gcore::Window window("Title", 1440, 750);
    window.setDrawer(new GraphCore(window));
    
    if (!window.make()) {
        fprintf(stderr, "Could not create glfw window.");
        return 1;
    }
    window.takeWindowContext();
    
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Could not initialize glew.\n");
        return 1;
    }
    
    window.startLoop();
    return 0;
}

int main(int argc, const char *argv[]) {
    
    if (!glfwInit()) {
        fprintf(stderr, "Could not initialize glfw.\n");
        return 1;
    }
    
    int exit_code = glfw_main(argc, argv);
    
    glfwTerminate();
    return exit_code;
}
