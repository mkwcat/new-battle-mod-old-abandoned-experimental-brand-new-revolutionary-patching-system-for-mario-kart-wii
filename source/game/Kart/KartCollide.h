#pragma once

#include "KartObjectProxy.h"

namespace Kart
{

class KartCollideAbstract
{
public:
    virtual void vt_8() = 0;
    virtual void vt_C() = 0;
    virtual ~KartCollideAbstract() = 0;
};

class KartCollide : public KartCollideAbstract, public KartObjectProxy
{
public:
    virtual void vt_8();
    virtual void vt_C();
    virtual ~KartCollide();

    EXTERN_TEXT(
      0x80573B00, //
      void ActivateOutOfBounds(
        int param_1, int param_2, int param_3, int param_4
      )
    );

    void UpdateRespawn(); // External 0x80573ED4
    void UpdateRespawnCall(); // Replaced 0x80573ED4
};

} // namespace Kart
