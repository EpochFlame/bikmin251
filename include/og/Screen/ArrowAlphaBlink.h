#ifndef _OG_SCREEN_ARROWALPHABLINK_H
#define _OG_SCREEN_ARROWALPHABLINK_H

#include "types.h"

namespace og {
namespace Screen {

/**
 * @size{0x10}
 */
struct ArrowAlphaBlink {
	void setSpeed(float speed);
	float calc();

	float m_timer;     // _00
	float m_speed;     // _04
	float m_magnitude; // _08
	float m_start;     // _0C
};
} // namespace Screen
} // namespace og

#endif
