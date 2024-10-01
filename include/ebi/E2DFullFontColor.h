#ifndef _EBI_E2DFULLFONTCOLOR_H
#define _EBI_E2DFULLFONTCOLOR_H

#include "JSystem/JUT/TColor.h"

namespace ebi {
// @size{0x10}
struct E2DFullFontColor {
	E2DFullFontColor();

	inline void setColors(J2DTextBox* pane)
	{
		mCol1.set(pane->m_color1);
		mCol2.set(pane->m_color2);
		m_white = pane->getWhite();
		m_black = pane->getBlack();
	}

	JUtility::TColor mCol1;     // _00
	JUtility::TColor mCol2;     // _04
	JUtility::TColor m_white; // _08
	JUtility::TColor m_black; // _0C
};
} // namespace ebi

#endif
