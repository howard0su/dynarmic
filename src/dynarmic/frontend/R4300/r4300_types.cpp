/* This file is part of the dynarmic project.
 * Copyright (c) 2018 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/frontend/R4300/r4300_types.h"

#include <array>
#include <ostream>

#include <fmt/format.h>

namespace Dynarmic::R4300 {

const char* CondToString(Cond cond) {
    static constexpr std::array cond_strs = {
        "eq", "ne", "hs", "lo", "mi", "pl", "vs", "vc",
        "hi", "ls", "ge", "lt", "gt", "le", "al", "nv"};
    return cond_strs.at(static_cast<size_t>(cond));
}

std::string RegToString(Reg reg) {
    return fmt::format("r{}", static_cast<size_t>(reg));
}

std::string VecToString(Vec vec) {
    return fmt::format("v{}", static_cast<size_t>(vec));
}

}  // namespace Dynarmic::R4300
