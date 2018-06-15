﻿/***********************************************************************************
**
** MultiMap.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#ifndef MULTIMAP_H
#define MULTIMAP_H

//Класс для работы с картой (multimap.rle)
class CMultiMap
{
public:
    CMultiMap();
    ~CMultiMap();

    //Загрузить карту
    void LoadMap(class CGumpMap *gump, class CGUIExternalTexture *map);

    bool LoadFacet(class CGumpMap *gump, class CGUIExternalTexture *map, int facet);
};

extern CMultiMap g_MultiMap;

#endif
