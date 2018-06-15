﻿/***********************************************************************************
**
** PathNode.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#include "stdafx.h"

CPathNode::CPathNode()
{
}

CPathNode::~CPathNode()
{
    m_Parent = NULL;
}

void CPathNode::Reset()
{
    m_Parent = NULL;
    Used = false;
    X = Y = Z = Direction = Cost = DistFromStartCost = DistFromGoalCost = 0;
}
