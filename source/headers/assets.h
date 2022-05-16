#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <experimental/filesystem>

enum assetType {image, music};

std::string findExtension(const std::string& fileName);
std::string formatPath(const std::string& path);
std::string formatAssetName(const std::string& fileName);

struct assetContainer {
    sf::Texture* texture;
    sf::Music* song;
    assetType type;
    const std::string* fileName;
    bool isLoaded;
    assetContainer(const std::string&);
};

struct assets {
    static std::vector<assetContainer*>* assetList;
    static bool loadAssets();
    static bool addAssets(const std::string& assetPath);
    static assetContainer* findAsset(const std::string& assetName);
};

#endif //ASSETS_H