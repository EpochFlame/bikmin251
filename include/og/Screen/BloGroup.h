#ifndef _OG_SCREEN_BLOGROUP_H
#define _OG_SCREEN_BLOGROUP_H

#include "P2DScreen.h"

namespace og {
namespace Screen {

/**
 * @size{0x10}
 */
struct BloGroup {
	BloGroup(u16);

	~BloGroup(); // unused/inlined

	u32 addBlo(char*, P2DScreen::Mgr_tuning*, u32, JKRArchive*);
	void scale(f32);
	void rotate(f32, f32, J2DRotateAxis, f32);
	void update();
	void draw(J2DPerspGraph*);

	// unused/inlined
	void setScissor(int, f32, f32, f32, f32);
	void translate(f32, f32);
	void setAlpha(u8);
	void animation();

	P2DScreen::Mgr_tuning** m_screens; // _00
	u32* _04;                          // _04, not sure if this is ever used
	u16 m_screenNumMax;                // _08
	u16 m_screenNumCurrent;            // _0A, number of ptrs in _00
};
} // namespace Screen
} // namespace og

#endif
