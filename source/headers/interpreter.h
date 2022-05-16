#ifndef INTERPRET_H
#define INTERPRET_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Path.h"
#include "enemy.h"

std::vector<Enemy*>* interpret(std::string levelName);

#endif // INTERPRET_H