#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include "headers\assets.h"

std::vector<assetContainer*>* assets::assetList;

bool assets::loadAssets() {
    namespace fs = std::experimental::filesystem;
    assetList = new std::vector<assetContainer*>;
    bool assetsLoaded = true;

    assetsLoaded = addAssets("sprites");
    assetsLoaded = addAssets("music");

    return assetsLoaded;
}

bool assets::addAssets(const std::string& assetPath) {
    for (const auto& entry : std::experimental::filesystem::directory_iterator(assetPath)) {
        std::string fileName;
        std::stringstream buffer;
        buffer << entry.path();
        fileName = formatPath(buffer.str());
        assetList->push_back(new assetContainer(fileName));
    }

    return true;
}

assetContainer* assets::findAsset(const std::string& assetName) {
    assetContainer* asset;

    for (int i = 0;i < assetList->size();i++) {
        if (*assetList->at(i)->fileName == assetName) {
            asset = assetList->at(i);
        }
    }

    return asset;
}

assetContainer::assetContainer(const std::string& fileName) {
    this->fileName = new std::string(formatAssetName(fileName));
    std::string extension = findExtension(fileName);

    if (extension == "png") {
        texture = new sf::Texture();
        texture->loadFromFile(fileName);
        isLoaded = true;
        type = image;
    } else if (extension == "flac") {
        song = new sf::Music;
        song->openFromFile(fileName);
        isLoaded = true;
        type = music;
    } else {
        isLoaded = false;
    }
}

std::string findExtension(const std::string& fileName) {
    std::string extension = "";
    bool passedDot = false;

    for (int i = 0;i < fileName.size();i++) {
        if (fileName[i] == '.') {
            passedDot = true;
        } else if (passedDot) {
            extension += fileName[i];
        }
    }

    return extension;
}

std::string formatPath(const std::string& path) {
    std::string fPath = "";
    bool formatSwitch = false;

    for (int i = 0;i < path.size();i++) {
        if (path[i] == '\\') {
            if (!formatSwitch) {
                formatSwitch = true;
                fPath += '/';
            }
        } else if (i != 0 && i != path.size() - 1) {
            fPath += path[i];
        }
    }

    return fPath;
}

std::string formatAssetName(const std::string& fileName) {
    std::string formattedName = "";
    bool copy = false;

    for (int i = 0;i < fileName.size();i++) {
        if (fileName[i] == '/') {
            copy = true;
        } else if (copy) {
            formattedName += fileName[i];
        }
    }

    return formattedName;
}