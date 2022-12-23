#ifndef _MOD_H
#define _MOD_H

namespace mod {
extern int keyLockCount;
extern bool isExitLocked;

// adjust treasure culling radius to 50.0f if radius was zero
float adjustBoundingRadius(float radius);

}; // namespace mod

#endif
