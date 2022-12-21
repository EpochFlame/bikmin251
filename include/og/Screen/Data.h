#ifndef _OG_DATA_H
#define _OG_DATA_H

#include "types.h"

namespace og {
namespace Screen {
enum MapPiki {
	MAPPIKI_Red    = 0,
	MAPPIKI_Yellow = 1,
	MAPPIKI_Blue   = 2,
	MAPPIKI_White  = 3,
	MAPPIKI_Purple = 4,
};

struct DataNavi {
	inline DataNavi()
	{
		m_naviLifeRatio = 1.0f;
		m_followPikis   = 1;
		m_nextThrowPiki = 2;
		m_dope1Count    = 10;
		m_dope0Count    = 10;
		m_activeNaviID  = 1;
	}

	f32 m_naviLifeRatio; // _00
	u32 m_followPikis;   // _04
	u32 m_nextThrowPiki; // _08
	u32 m_dope1Count;    // _0C
	u32 m_dope0Count;    // _10
	u8 m_activeNaviID;   // _14
};

struct DataGame {
	inline DataGame()
	{
		m_sunGaugeRatio    = 0.0f;
		m_dayNum           = 0;
		m_floorNum         = 0;
		m_totalPikminCount = 1234;
		m_mapPikminCount   = 50;
		_14                = false;
		m_pokoCount        = 0;
	}

	f32 m_sunGaugeRatio;    // _00
	int m_dayNum;           // _04
	int m_totalPikminCount; // _08
	int m_floorNum;         // _0C
	int m_mapPikminCount;   // _10
	u8 _14;                 // _14
	uint m_pokoCount;       // _18
};

struct DataMap {
	u32 m_napsackDetectorFlags;   // _00
	u32 m_onyonPikminCounts[5];   // _04, indexed by MapPiki enum
	u32 m_currentPikminCounts[5]; // _18, indexed by MapPiki enum
	u32 m_freePikmin;             // _2C
	u32 m_pokos;                  // _30
};
} // namespace Screen
} // namespace og

#endif
