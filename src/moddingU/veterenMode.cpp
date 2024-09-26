#include "Game/Navi.h"
#include "Game/NaviParms.h"
#include "Game/PikiMgr.h"
#include "Game/PikiParms.h"
#include "Game/Data.h"
#include "JSystem/JKR/JKRDvdRipper.h"

namespace Game {

const char* casualPath  = "user/Abe/piki/";
const char* veteranPath = "user/Abe/piki/pikiNormalMode/";

void getParmsPath(char* pathBuf, const char* name)
{
    if (sys->getPlayCommonData()->mVeteranMode) {
        sprintf(pathBuf, "%s%s", veteranPath, name);   
    } else {
        sprintf(pathBuf, "%s%s", casualPath, name);
    }
}

void NaviMgr::loadResources()
{   
    char pathBuf[256];
    getParmsPath(pathBuf, "naviParms.txt");
	void* parmsFile = JKRDvdRipper::loadToMainRAM(pathBuf, nullptr, Switch_0, 0, nullptr,
	                                              JKRDvdRipper::ALLOC_DIR_BOTTOM, 0, nullptr, nullptr);
	if (parmsFile) {
		RamStream stream(parmsFile, -1);
		stream.setMode(STREAM_MODE_TEXT, 1);
		m_naviParms->read(stream);
		delete[] parmsFile;
	}

	load();
}

void PikiMgr::loadResources(int viewNum)
{
    char pathBuf[256];
    getParmsPath(pathBuf, "pikiParms.txt");
	void* file
	    = JKRDvdRipper::loadToMainRAM(pathBuf, 0, Switch_0, 0, nullptr, JKRDvdRipper::ALLOC_DIR_BOTTOM, 0, 0, 0);
	if (file) {
		RamStream stream(file, -1);
		stream.setMode(STREAM_MODE_TEXT, 1);
		m_parms->read(stream);
		delete[] file;
	}
	load(viewNum);
}
    
} // namespace Game
