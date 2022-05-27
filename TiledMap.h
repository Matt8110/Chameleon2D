#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "tinyxml2.h"

using namespace tinyxml2;

struct STile
{
    int id;
};

struct SLayer
{
    std::string name;
    std::vector<STile> tiles;
};

class CMap
{
public:
    CMap(const std::string& mapFile);
    const SLayer& getLayer(const std::string& layerName);
    const SLayer& getLayer(unsigned int layerID);
    
private:
    std::vector<SLayer> m_layers;
    std::string m_filename;
    int m_width;
    int m_height;
    int m_tileWidth;
    int m_tileHeight;

    void loadLayers();
    std::vector<int> splitMapData(const std::string& data);
};