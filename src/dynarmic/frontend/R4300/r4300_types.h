/* This file is part of the dynarmic project.
 * Copyright (c) 2018 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <string>

#include <fmt/format.h>
#include <mcl/assert.hpp>
#include <mcl/stdint.hpp>

#include "dynarmic/ir/cond.h"

namespace Dynarmic::R4300 {

using Cond = IR::Cond;

enum class Reg {
	R0 = 0,
	AT,
    V0,
    V1,
    A0,
    A1,
    A2,
    A3,
	T0,
    T1,
    T2,
    T3,
    T4,
    T5,
    T6,
    T7,
	S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
	T8,
    T9,
    K0,
    K1,
    GP,
    SP,
    S8,
    RA,
};

enum class Vec {
    V0,
    V1,
    V2,
    V3,
    V4,
    V5,
    V6,
    V7,
    V8,
    V9,
    V10,
    V11,
    V12,
    V13,
    V14,
    V15,
    V16,
    V17,
    V18,
    V19,
    V20,
    V21,
    V22,
    V23,
    V24,
    V25,
    V26,
    V27,
    V28,
    V29,
    V30,
    V31,
};

enum class ShiftType {
    LSL,
    LSR,
    ASR,
    ROR,
};

const char* CondToString(Cond cond);
std::string RegToString(Reg reg);
std::string VecToString(Vec vec);

constexpr size_t RegNumber(Reg reg) {
    return static_cast<size_t>(reg);
}

constexpr size_t VecNumber(Vec vec) {
    return static_cast<size_t>(vec);
}

inline Reg operator+(Reg reg, size_t number) {
    const size_t new_reg = RegNumber(reg) + number;
    ASSERT(new_reg <= 31);

    return static_cast<Reg>(new_reg);
}

inline Vec operator+(Vec vec, size_t number) {
    const size_t new_vec = VecNumber(vec) + number;
    ASSERT(new_vec <= 31);

    return static_cast<Vec>(new_vec);
}

}  // namespace Dynarmic::R4300

template<>
struct fmt::formatter<Dynarmic::R4300::Reg> : fmt::formatter<std::string> {
    template<typename FormatContext>
    auto format(Dynarmic::R4300::Reg reg, FormatContext& ctx) const {
        return formatter<std::string>::format(Dynarmic::R4300::RegToString(reg), ctx);
    }
};

template<>
struct fmt::formatter<Dynarmic::R4300::Vec> : fmt::formatter<std::string> {
    template<typename FormatContext>
    auto format(Dynarmic::R4300::Vec vec, FormatContext& ctx) const {
        return formatter<std::string>::format(Dynarmic::R4300::VecToString(vec), ctx);
    }
};
