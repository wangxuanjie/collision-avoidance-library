/*
// Copyright (c) 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#pragma once

#include <memory>

#include <coav/coav.hh>

#include <GL/gl.h>

using namespace std;

class VisualDepth
{
public:
    VisualDepth(int x, int y, unsigned int width, unsigned int height);
    ~VisualDepth();
    void info();
    void rainbow_scale(double value, uint8_t rgb[]);
    void visualize(shared_ptr<DepthData> depth_data);
    void set_viewport(int x, int y, unsigned int width, unsigned int height);

private:
    int x;
    int y;

    unsigned int width;
    unsigned int height;

    GLuint texture;
    uint8_t *frame_buffer;
    size_t frame_buffer_size;
};

struct VisualData
{
    struct {
        unsigned int width;
        unsigned int height;

        int ref;
    } window;

    struct {
        shared_ptr<MavQuadCopter> vehicle;
        shared_ptr<DepthCamera> sensor;
        shared_ptr<Detector> detector;
        shared_ptr<CollisionAvoidanceStrategy<MavQuadCopter>> avoidance;

        shared_ptr<DepthData> depth_data;
    } coav;

    shared_ptr<VisualDepth> depth;
};

void visual_mainlopp(int argc, char* argv[], shared_ptr<MavQuadCopter> vehicle,
        shared_ptr<DepthCamera> sensor, shared_ptr<Detector> detector,
        shared_ptr<CollisionAvoidanceStrategy<MavQuadCopter>> avoidance);