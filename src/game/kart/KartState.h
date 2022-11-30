#pragma once

namespace kart
{

class KartState
{
public:
    FILL(0x0, 0x4);

    enum {
        FLAGS0_ACCELERATE = (1 << 0), // 0x1
        FLAGS0_BRAKE = (1 << 1), // 0x2
        FLAGS0_DRIFT_INPUT = (1 << 2), // 0x4
        FLAGS0_DRIFT_MANUAL = (1 << 3), // 0x8
        FLAGS0_PRE_RESPAWN = (1 << 4), // 0x10
        FLAGS0_WALL_3_COLLISION = (1 << 5), // 0x20
        FLAGS0_WALL_COLLISION = (1 << 6), // 0x40
        FLAGS0_HOP_START = (1 << 7), // 0x80
        FLAGS0_ACCELERATE_START = (1 << 8), // 0x100
        FLAGS0_GROUND_START = (1 << 9), // 0x200
        FLAGS0_VEHICLE_BODY_FLOOR_COLLISION = (1 << 10), // 0x400
        FLAGS0_ANY_WHEEL_COLLISION = (1 << 11), // 0x800
        FLAGS0_ALL_WHEELS_COLLISION = (1 << 12), // 0x1000
        FLAGS0_STICK_LEFT = (1 << 13), // 0x2000
        FLAGS0_UNKNOWN_14 = (1 << 14), // 0x4000
        FLAGS0_AIRTIME_OVER_20 = (1 << 15), // 0x8000
        FLAGS0_STICKY_ROAD = (1 << 16), // 0x10000
        FLAGS0_UNKNOWN_17 = (1 << 17), // 0x20000
        FLAGS0_GROUND = (1 << 18), // 0x40000
        FLAGS0_HOP = (1 << 19), // 0x80000
        FLAGS0_BOOST = (1 << 20), // 0x100000
        FLAGS0_UNKNOWN_21 = (1 << 21), // 0x200000
        FLAGS0_UNKNOWN_22 = (1 << 22), // 0x400000
        FLAGS0_AIR_START = (1 << 23), // 0x800000
        FLAGS0_STICK_RIGHT = (1 << 24), // 0x1000000
        FLAGS0_UNKNOWN_EXPLOSION = (1 << 25), // 0x2000000
        FLAGS0_MUSHROOM_BOOST = (1 << 26), // 0x4000000
        FLAGS0_SLIPDRIFT_CHARGE = (1 << 27), // 0x8000000
        FLAGS0_DRIFT_AUTO = (1 << 28), // 0x10000000
        FLAGS0_WHEELIE = (1 < 29), // 0x20000000
        FLAGS0_JUMP_PAD = (1 << 30), // 0x40000000
        FLAGS0_RAMP_BOOST = (1 << 31), // 0x80000000
    };

    enum {
        FLAGS1_HIT_ITEM_OR_OBJ = (1 << 0), // 0x1
        FLAGS1_RESPAWN_START = (1 << 1), // 0x2
        FLAGS1_UNKNOWN_2 = (1 << 2), // 0x4
        FLAGS1_CANNON_START = (1 << 3), // 0x8
        FLAGS1_IN_CANNON = (1 << 4), // 0x10
        FLAGS1_TRICK_START = (1 << 5), // 0x20
        FLAGS1_IN_A_TRICK = (1 << 6), // 0x40
        FLAGS1_BOOST_OFFROAD_INVINCIBILITY = (1 << 7), // 0x80
        FLAGS1_BLINKING = (1 << 8), // 0x100
        FLAGS1_ZIPPER_COLLISION = (1 << 9), // 0x200
        FLAGS1_OVER_ZIPPER = (1 << 10), // 0x400
        FLAGS1_MUSHROOM_COLLISION = (1 << 11), // 0x800
        FLAGS1_UNKNOWN_12 = (1 << 12), // 0x1000
        FLAGS1_ZIPPER_BOOST = (1 << 13), // 0x2000
        FLAGS1_UNKNOWN_14 = (1 << 14), // 0x4000
        FLAGS1_ZIPPER_TRICK = (1 << 15), // 0x8000
        FLAGS1_UNKNOWN_16 = (1 << 16), // 0x10000
        FLAGS1_UNKNOWN_17 = (1 << 17), // 0x20000
        FLAGS1_UNKNOWN_18 = (1 << 18), // 0x40000
        FLAGS1_UNKNOWN_19 = (1 << 19), // 0x80000
        FLAGS1_MT_BOOST = (1 << 20), // 0x100000
        FLAGS1_UNKNOWN_21 = (1 << 21), // 0x200000
        FLAGS1_HAS_TRICK_ROT = (1 << 22), // 0x400000
        FLAGS1_UNKNOWN_23 = (1 << 23), // 0x800000
        FLAGS1_UNKNOWN_24 = (1 << 24), // 0x1000000
        FLAGS1_UNKNOWN_25 = (1 << 25), // 0x2000000
        FLAGS1_UNKNOWN_26 = (1 << 26), // 0x4000000
        FLAGS1_UNKNOWN_27 = (1 << 27), // 0x8000000
        FLAGS1_UNKNOWN_28 = (1 << 28), // 0x10000000
        FLAGS1_UNKNOWN_29 = (1 < 29), // 0x20000000
        FLAGS1_TRICKABLE = (1 << 30), // 0x40000000
        FLAGS1_IN_A_STAR = (1 << 31), // 0x80000000
    };

    enum {
        FLAGS2_CHARGING_A_SLIPSTREAM = (1 << 0), // 0x1
        FLAGS2_IN_A_SLIPSTREAM = (1 << 1), // 0x2
        FLAGS2_SOMETHING_WHEELIE_BUMP = (1 << 2), // 0x4
        FLAGS2_UNKNOWN_3 = (1 << 3), // 0x8
        FLAGS2_WHEELIE_ROT = (1 << 4), // 0x10
        FLAGS2_SHOCKED = (1 << 5), // 0x20
        FLAGS2_UNKNOWN_6 = (1 << 6), // 0x40
        FLAGS2_UNKNOWN_7 = (1 << 7), // 0x80
        FLAGS2_UNKNOWN_8 = (1 << 8), // 0x100
        FLAGS2_UNKNOWN_9 = (1 << 9), // 0x200
        FLAGS2_UNKNOWN_10 = (1 << 10), // 0x400
        FLAGS2_UNKNOWN_11 = (1 << 11), // 0x800
        FLAGS2_UNKNOWN_12 = (1 << 12), // 0x1000
        FLAGS2_MAYBE_POST_RESPAWN = (1 << 13), // 0x2000
        FLAGS2_MAYBE_POST_RESPAWN2 = (1 << 14), // 0x4000
        FLAGS2_IN_A_MEGA = (1 << 15), // 0x8000
        FLAGS2_CRUSHED = (1 << 16), // 0x10000
        FLAGS2_UNKNOWN_17 = (1 << 17), // 0x20000
        FLAGS2_HAS_STOPPED = (1 << 18), // 0x40000
        FLAGS2_HAS_VANISHED = (1 << 19), // 0x80000
        FLAGS2_UNKNOWN_20 = (1 << 20), // 0x100000
        FLAGS2_UNKNOWN_21 = (1 << 21), // 0x200000
        FLAGS2_HAS_JUMP_PAD_DIR = (1 << 22), // 0x400000
        FLAGS2_UNKNOWN_23 = (1 << 23), // 0x800000
        FLAGS2_UNKNOWN_24 = (1 << 24), // 0x1000000
        FLAGS2_UNKNOWN_25 = (1 << 25), // 0x2000000
        FLAGS2_UNKNOWN_26 = (1 << 26), // 0x4000000
        FLAGS2_IN_A_BULLET = (1 << 27), // 0x8000000
        FLAGS2_INK_APPLIED = (1 << 28), // 0x10000000
        FLAGS2_IN_A_TC = (1 < 29), // 0x20000000
        FLAGS2_UNKNOWN_30 = (1 << 30), // 0x40000000
        FLAGS2_UNKNOWN_31 = (1 << 31), // 0x80000000
    };

    enum {
        FLAGS3_UNKNOWN_WALL_COLLISION = (1 << 3), // 0x8
        FLAGS3_HWG = (1 << 5), // 0x20
        FLAGS3_CHARGE_START_BOOST = (1 << 8), // 0x100
    };

    enum {
        FLAGS4_CPU = (1 << 0), // 0x1
        FLAGS4_LOCAL = (1 << 1), // 0x2
        FLAGS4_ONLINE_LOCAL = (1 << 2), // 0x4
        FLAGS4_ONLINE_REMOTE = (1 << 3), // 0x8
        FLAGS4_AUTOMATIC_DRIFT = (1 << 4), // 0x10
        FLAGS4_GHOST = (1 << 5), // 0x40
        FLAGS4_HAS_STOPPED = (1 << 12), // 0x1000
        FLAGS4_BATTLE_SIDELINE = (1 << 16), // 0x10000
        FLAGS4_TRIGGER_RESPAWN = (1 << 17), // 0x20000

        // These flags are added:
        FLAGS4_POST_BATTLE_SIDELINE = (1 << 31), // 0x80000000
    };

    u32 m_flags0;
    u32 m_flags1;
    u32 m_flags2;
    u32 m_flags3;
    u32 m_flags4;
};

} // namespace kart
