#ifndef _DROUGHT_MISC_H_
#define _DROUGHT_MISC_H_

#include "Vector3.h"
#include "Game/CurrTriInfo.h"
#include "Game/MapMgr.h"

namespace Drought
{

    inline bool hasValidFloor(Vector3f& vec) {
        Game::CurrTriInfo triSpawn;
        triSpawn.m_triangle = nullptr;
        triSpawn._18 = 128000.0f;
        triSpawn._1C = -128000.0f;
        triSpawn.m_table = nullptr;
        triSpawn._20 = Vector3f(0.0f, 1.0f, 0.0f);
        triSpawn._0D = 0;
        triSpawn._00 = vec;
        triSpawn._0C = 0;
        Game::mapMgr->getCurrTri(triSpawn);
        return triSpawn.m_triangle;
    }

} // namespace Drought


#endif