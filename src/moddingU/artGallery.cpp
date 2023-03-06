#include "types.h"
#include "Game/gamePlayData.h"
#include "Game/Data.h"
#include "Morimura/VsSelect.h"

const char* getVsTextureResName()
{
	if (sys->getPlayCommonData()->challenge_checkClear(0)) {
		return "res_vsSelectTexture.szs";
	} else {
		return "res_vsSelectTextureHide.szs";
	}
}
