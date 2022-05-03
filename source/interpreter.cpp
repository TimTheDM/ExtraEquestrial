#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "headers\Path.h"
#include "headers\enemy.h"

std::string filterSpace(std::string line);

std::vector<Enemy*>* interpret(std::string levelName)
{
    bool constructEnemy = false;
    bool constructPath = false;
    std::string line;
    int tempXpos;
    int tempYpos;
    std::string tempType;
    int tempTimer;
    float tempAngle;
    float tempMutation;
    std::vector<Path*>* tempPath;
    Enemy* tempEnemy;
    std::vector<Enemy*>* levelEnemies;
    std::ifstream levelFile(levelName);
    if(levelFile.is_open())
    {
        while(std::getline(levelFile, line))
        {
            line = filterSpace(line);

            if(line == "enemy=")
            {
                std::cout << "Enemy creation initiated." << '\n';
            }
            if(line.substr(0,5) == "type=")
            {
                std::cout << "Type initialized to " << line.substr(5, line.length()) << '\n';
                tempType = line.substr(5, line.length());
                //Create function to turn strings to all lowercase
            }
            if(line.substr(0,9) == "position=")
            {
                 std::cout << "Position initialized to " << line[9] << ',' << line[11] << '\n';
                 tempXpos = line[9];
                 tempYpos = line[11];
            }
            if(line == "path=")
            {
                 std::cout << "Path creation initiated." << '\n';
            }
            if(line.substr(0,6) == "timer=")
            {
                std::cout << "Timer initialized to " << line.substr(6, line.length()) << '\n';
                tempTimer = std::stoi(line.substr(6, line.length()));
            }
            if(line.substr(0,6) == "angle=")
            {
                std::cout << "Angle initialized to " << line.substr(6, line.length()) << '\n';
                tempAngle = std::stof(line.substr(6, line.length()));
            }
            if(line.substr(0,9) == "mutation=")
            {
                std::cout << "Mutation initialized to " << line.substr(9, line.length()) << '\n';
                tempMutation = std::stof(line.substr(9, line.length()));
            }

            if(line == "}" && constructEnemy == true && constructPath == true)
            {
                std::cout << "Path construction completed." << '\n';
                tempPath->push_back(new Path(tempTimer, tempAngle, tempMutation));
            }
            else if(line == "}" && constructEnemy == true && constructPath == false)
            {
                std::cout << "Enemy construction completed." << '\n';
                tempEnemy = new Enemy(tempXpos, tempYpos, tempType, tempPath);
                levelEnemies->push_back(tempEnemy);
            }
            else if(line == "}" && constructEnemy == false && constructPath == false)
            {
                break;
            }
        }
        levelFile.close();
        return levelEnemies;
    }
    else std::cout << "Unable to open level file";
}

std::string filterSpace(std::string line)
{
    int lineLength = line.length();
    std::string spaceFreeStr;

    for(int i = 0; i < lineLength; i++)
    {
        if(line[i] != ' ' && line[i] != '\t')
        {
            spaceFreeStr += line[i];
        }
    }

    return spaceFreeStr;
}