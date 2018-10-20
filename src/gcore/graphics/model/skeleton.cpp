//
// => gcore/model/skeleton.cpp
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

#include <gcore/graphics/model/skeleton.h>

#include <cstdint>

#include <iostream>

using namespace gcore;

void Skeleton::resetJoint(uint32_t boneID) {
    SkeletonBone *bone = bones[boneID];
    
    glm::mat4 joint = bone->getNodeTransform() * bone->getOffsetMatrix();
    
    while ((bone = bone->getParent())) {
        joint = bone->getNodeTransform() * joint;
    }
    
    joints[boneID] = finalTransform * joint;
}

void Skeleton::resetAllJoints() {
    for (uint32_t i = 0; i < bonesCount; i++) {
        resetJoint(i);
    }
}
