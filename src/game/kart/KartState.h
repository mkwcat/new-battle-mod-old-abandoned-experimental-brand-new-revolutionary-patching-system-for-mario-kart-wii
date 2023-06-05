#pragma once

namespace Kart
{

class KartState
{
public:
    FILL(0x0, 0x4);

    // Converted flags to bitfields

    // Bitfield 0
    u32 b_RampBoost : 1; // (1 << 31), 0x80000000
    u32 b_JumpPad : 1; // (1 << 30), 0x40000000
    u32 b_Wheelie : 1; // (1 < 29), 0x20000000
    u32 b_DriftAuto : 1; // (1 << 28), 0x10000000
    u32 b_SlipdriftCharge : 1; // (1 << 27), 0x8000000
    u32 b_MushroomBoost : 1; // (1 << 26), 0x4000000
    u32 b_UnknownExplosion : 1; // (1 << 25), 0x2000000
    u32 b_StickRight : 1; // (1 << 24), 0x1000000
    u32 b_AirStart : 1; // (1 << 23), 0x800000
    u32 b_Unknown0_22 : 1; // (1 << 22), 0x400000
    u32 b_Unknown0_21 : 1; // (1 << 21), 0x200000
    u32 b_Boost : 1; // (1 << 20), 0x100000
    u32 b_Hop : 1; // (1 << 19), 0x80000
    u32 b_Ground : 1; // (1 << 18), 0x40000
    u32 b_Unknown017 : 1; // (1 << 17), 0x20000
    u32 b_StickyRoad : 1; // (1 << 16), 0x10000
    u32 b_AirtimeOver20 : 1; // (1 << 15), 0x8000
    u32 b_Unknown0_14 : 1; // (1 << 14), 0x4000
    u32 b_StickLeft : 1; // (1 << 13), 0x2000
    u32 b_AllWheelsCollision : 1; // (1 << 12), 0x1000
    u32 b_AnyWheelCollision : 1; // (1 << 11), 0x800
    u32 b_VehicleBodyFloorCollision : 1; // (1 << 10), 0x400
    u32 b_GroundStart : 1; // (1 << 9), 0x200
    u32 b_AccelerateStart : 1; // (1 << 8), 0x100
    u32 b_HopStart : 1; // (1 << 7), 0x80
    u32 b_WallCollision : 1; // (1 << 6), 0x40
    u32 b_Wall3Collision : 1; // (1 << 5), 0x20
    u32 b_PreRespawn : 1; // (1 << 4), 0x10
    u32 b_DriftManual : 1; // (1 << 3), 0x8
    u32 b_DriftInput : 1; // (1 << 2), 0x4
    u32 b_Brake : 1; // (1 << 1), 0x2
    u32 b_Accelerate : 1; // (1 << 0), 0x1

    // Bitfield 1
    u32 b_InAStar : 1; // (1 << 31), 0x80000000
    u32 b_Trickable : 1; // (1 << 30), 0x40000000
    u32 b_Unknown1_29 : 1; // (1 < 29), 0x20000000
    u32 b_Unknown1_28 : 1; // (1 << 28), 0x10000000
    u32 b_Unknown1_27 : 1; // (1 << 27), 0x8000000
    u32 b_Unknown1_26 : 1; // (1 << 26), 0x4000000
    u32 b_Unknown1_25 : 1; // (1 << 25), 0x2000000
    u32 b_Unknown1_24 : 1; // (1 << 24), 0x1000000
    u32 b_Unknown1_23 : 1; // (1 << 23), 0x800000
    u32 b_HasTrickRot : 1; // (1 << 22), 0x400000
    u32 b_Unknown121 : 1; // (1 << 21), 0x200000
    u32 b_MiniturboBoost : 1; // (1 << 20), 0x100000
    u32 b_Unknown1_19 : 1; // (1 << 19), 0x80000
    u32 b_Unknown1_18 : 1; // (1 << 18), 0x40000
    u32 b_Unknown1_17 : 1; // (1 << 17), 0x20000
    u32 b_Unknown1_16 : 1; // (1 << 16), 0x10000
    u32 b_ZipperTrick : 1; // (1 << 15), 0x8000
    u32 b_Unknown1_14 : 1; // (1 << 14), 0x4000
    u32 b_ZipperBoost : 1; // (1 << 13), 0x2000
    u32 b_Unknown1_12 : 1; // (1 << 12), 0x1000
    u32 b_MushroomCollision : 1; // (1 << 11), 0x800
    u32 b_OverZipper : 1; // (1 << 10), 0x400
    u32 b_ZipperCollision : 1; // (1 << 9), 0x200
    u32 b_Blinking : 1; // (1 << 8), 0x100
    u32 b_BoostOffroadInvincibility : 1; // (1 << 7), 0x80
    u32 b_InATrick : 1; // (1 << 6), 0x40
    u32 b_TrickStart : 1; // (1 << 5), 0x20
    u32 b_InCannon : 1; // (1 << 4), 0x10
    u32 b_CannonStart : 1; // (1 << 3), 0x8
    u32 b_Unknown1_2 : 1; // (1 << 2), 0x4
    u32 b_RespawnStart : 1; // (1 << 1), 0x2
    u32 b_HitItemOrObj : 1; // (1 << 0), 0x1

    // Bitfield 2
    u32 b_Unknown2_31 : 1; // (1 << 31), 0x80000000
    u32 b_Unknown2_30 : 1; // (1 << 30), 0x40000000
    u32 b_HasThunderCloud : 1; // (1 < 29), 0x20000000
    u32 b_InkApplied : 1; // (1 << 28), 0x10000000
    u32 b_InABullet : 1; // (1 << 27), 0x8000000
    u32 b_Unknown2_26 : 1; // (1 << 26), 0x4000000
    u32 b_Unknown2_25 : 1; // (1 << 25), 0x2000000
    u32 b_Unknown2_24 : 1; // (1 << 24), 0x1000000
    u32 b_Unknown2_23 : 1; // (1 << 23), 0x800000
    u32 b_HasJumpPadDir : 1; // (1 << 22), 0x400000
    u32 b_Unknown2_21 : 1; // (1 << 21), 0x200000
    u32 b_Unknown2_20 : 1; // (1 << 20), 0x100000
    u32 b_HasVanished : 1; // (1 << 19), 0x80000
    u32 b_HasStoppedB2 : 1; // (1 << 18), 0x40000
    u32 b_Unknown2_17 : 1; // (1 << 17), 0x20000
    u32 b_Crushed : 1; // (1 << 16), 0x10000
    u32 b_InAMega : 1; // (1 << 15), 0x8000
    u32 b_MaybePostRespawn2 : 1; // (1 << 14), 0x4000
    u32 b_MaybePostRespawn : 1; // (1 << 13), 0x2000
    u32 b_Unknown2_12 : 1; // (1 << 12), 0x1000
    u32 b_Unknown2_11 : 1; // (1 << 11), 0x800
    u32 b_Unknown2_10 : 1; // (1 << 10), 0x400
    u32 b_Unknown2_9 : 1; // (1 << 9), 0x200
    u32 b_Unknown2_8 : 1; // (1 << 8), 0x100
    u32 b_Unknown2_7 : 1; // (1 << 7), 0x80
    u32 b_Unknown2_6 : 1; // (1 << 6), 0x40
    u32 b_Shocked : 1; // (1 << 5), 0x20
    u32 b_WheelieRot : 1; // (1 << 4), 0x10
    u32 b_Unknown2_3 : 1; // (1 << 3), 0x8
    u32 b_SomethingWheelieBump : 1; // (1 << 2), 0x4
    u32 b_InASlipstream : 1; // (1 << 1), 0x2
    u32 b_ChargingASlipstream : 1; // (1 << 0), 0x1

    // Unknown flags
    u32 m_bitfield3;

    // Bitfield 4
    // These flags are added:
    u32 b_PostBattleSideline : 1; // (1 << 31) 0x80000000
    u32 b_Pad4 : 13;

    // These flags are original:
    u32 b_BattleRespawn : 1; // (1 << 17), 0x20000
    u32 b_BattleSideline : 1; // (1 << 16), 0x10000
    u32 b_Unknown4_15 : 1; // (1 << 15), 0x8000
    u32 b_Unknown4_14 : 1; // (1 << 14), 0x4000
    u32 b_Unknown4_13 : 1; // (1 << 13), 0x2000
    u32 b_HasStoppedB4 : 1; // (1 << 12), 0x1000
    u32 b_Unknown4_11 : 1; // (1 << 11), 0x800
    u32 b_Unknown4_10 : 1; // (1 << 10), 0x400
    u32 b_Unknown4_9 : 1; // (1 << 9), 0x200
    u32 b_Unknown4_8 : 1; // (1 << 8), 0x100
    u32 b_Unknown4_7 : 1; // (1 << 7), 0x80
    u32 b_Ghost : 1; // (1 << 6), 0x40
    u32 b_Unknown45 : 1; // (1 << 5), 0x20
    u32 b_AutomaticDrift : 1; // (1 << 4), 0x10
    u32 b_OnlineRemote : 1; // (1 << 3), 0x8
    u32 b_OnlineLocal : 1; // (1 << 2), 0x4
    u32 b_Local : 1; // (1 << 1), 0x2
    u32 b_CPU : 1; // (1 << 0), 0x1
};

} // namespace Kart
