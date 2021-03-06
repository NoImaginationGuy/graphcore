//
// => gcore/model/model.h
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

#ifndef __graphcore_graphics_model
#define __graphcore_graphics_model

#include <gcore/graphics/opengl.h>
#include <gcore/graphics/model/skeleton.h>
#include <gcore/graphics/model/animation.h>

#include <vector>

namespace gcore {
    
    /*!
     \brief Class implementing an imported model, keeping all the data needed to draw, as well as methods for drawing the model in the current context.
     */
    class Model {
        
        uint32_t meshCount;
        VertexArrayObject **vaos;
        
        
        
        
        
        
        
        Skeleton *_skeleton;
        
        uint32_t _animCount;
        Animation **_animations;
        
        Model() {  }
        
    public:
        ~Model() {
            delete vaos;
            
            

            delete _animations;
        }
        
        void update(double dt);
        
        void draw(GLint jointsUniform);
        
        
        static Model *fromFile(const char *fileName);
        
    };
    
}

#endif
