#include "TiledMap.h"

CMap::CMap(const std::string& mapFile)
{
    m_filename = mapFile;
    loadLayers();
}

const SLayer& CMap::getLayer(const std::string& layerName)
{
    try{
        for (int i = 0; i < m_layers.size(); i++)
        {
            if (layerName.compare(m_layers.at(i).name) == 0)
                return m_layers.at(i);
        }

        throw(100);
    }catch(int e)
    {
        std::cout << "Error: failed to find layer " << layerName << std::endl;
    }
}

const SLayer& CMap::getLayer(unsigned int layerID)
{
    try{
        if (layerID >= m_layers.size())
            throw(101);

        return m_layers.at(layerID);
        
    }catch(int e)
    {
        std::cout << "Error: failed to find layer " << std::to_string(layerID) << std::endl;
    }
}

void CMap::loadLayers()
{
    XMLDocument document;
    document.LoadFile(m_filename.c_str());

    XMLElement* rootElem = document.RootElement();

    if (rootElem == nullptr)
    {
        std::cout << "Error: Failed to get root node" << std::endl;
        return;
    }

    m_width = rootElem->IntAttribute("width");
    m_height = rootElem->IntAttribute("height");
    m_tileWidth = rootElem->IntAttribute("tilewidth");
    m_tileHeight = rootElem->IntAttribute("tileheight");

    XMLElement* currentLayerElem = rootElem->FirstChildElement("layer");

    if (currentLayerElem == nullptr)
    {
        std::cout << "Error: No layers!!" << std::endl;
        return;
    }

    while (currentLayerElem != nullptr)
    {
        SLayer layer;
        layer.name = currentLayerElem->Attribute("name");

        XMLElement* dataElem = currentLayerElem->FirstChildElement("data");
        if (currentLayerElem == nullptr)
        {
            std::cout << "Error: Layer " << layer.name <<  " does not contain data!" << std::endl;
            return;
        }

        std::string layerData = dataElem->GetText();

        //Convert data to tile vector
        std::vector<int> mapData = splitMapData(layerData);

        for (int i = 0; i < mapData.size(); i++)
        {
            STile tile{mapData.at(i)};
            layer.tiles.push_back(tile);
        }

        mapData.clear();

        m_layers.push_back(layer);

        currentLayerElem = currentLayerElem->NextSiblingElement("layer");
    }
    
    document.Clear();

}

std::vector<int> CMap::splitMapData(const std::string& data)
{
    std::vector<int> outVec;
    std::stringstream ss(data);

    for (int i; ss >> i;)
    {
        outVec.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    return outVec;
}