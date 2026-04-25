#pragma once
#include "GameObject.h"
#include "ShaderProgram.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Game
{
    vector<GameObject> gameObjects;
    vector<ShaderProgram> shaderPrograms;
};

