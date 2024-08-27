/* This file is part of the dynarmic project.
 * Copyright (c) 2016 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <functional>
#include <string>
#include <tuple>

#include <fmt/format.h>
#include <mcl/bit/bit_field.hpp>
#include <mcl/stdint.hpp>

#include "dynarmic/common/fp/fpcr.h"
#include "dynarmic/ir/location_descriptor.h"

namespace Dynarmic::R4300 {

/**
 * LocationDescriptor describes the location of a basic block.
 * The location is not solely based on the PC because other flags influence the way
 * instructions should be translated.
 */
class LocationDescriptor {
public:
    static constexpr size_t single_stepping_bit = 1;

    LocationDescriptor(u32 pc, bool single_stepping = false)
            : pc(pc), single_stepping(single_stepping) {}

    explicit LocationDescriptor(const IR::LocationDescriptor& o)
            : pc(o.Value())
            , single_stepping(mcl::bit::get_bit<single_stepping_bit>(o.Value())) {}

    u32 PC() const { return pc; }
    bool SingleStepping() const { return single_stepping; }

    bool operator==(const LocationDescriptor& o) const {
        return std::tie(pc, single_stepping) == std::tie(o.pc, o.single_stepping);
    }

    bool operator!=(const LocationDescriptor& o) const {
        return !operator==(o);
    }

    LocationDescriptor SetPC(u64 new_pc) const {
        return LocationDescriptor(new_pc, single_stepping);
    }

    LocationDescriptor AdvancePC(int amount) const {
        return LocationDescriptor(static_cast<u64>(pc + amount), single_stepping);
    }

    LocationDescriptor SetSingleStepping(bool new_single_stepping) const {
        return LocationDescriptor(pc, new_single_stepping);
    }

    u64 UniqueHash() const noexcept {
        // This value MUST BE UNIQUE.
        // This calculation has to match up with EmitTerminalPopRSBHint
        const u64 single_stepping_u64 = static_cast<u64>(single_stepping) << single_stepping_bit;
        return pc | single_stepping_u64;
    }

    operator IR::LocationDescriptor() const {
        return IR::LocationDescriptor{UniqueHash()};
    }

private:
    u64 pc;         ///< Current program counter value.
    bool single_stepping;
};

/**
 * Provides a string representation of a LocationDescriptor.
 *
 * @param descriptor The descriptor to get a string representation of
 */
std::string ToString(const LocationDescriptor& descriptor);

}  // namespace Dynarmic::R4300

namespace std {
template<>
struct less<Dynarmic::R4300::LocationDescriptor> {
    bool operator()(const Dynarmic::R4300::LocationDescriptor& x, const Dynarmic::R4300::LocationDescriptor& y) const noexcept {
        return x.UniqueHash() < y.UniqueHash();
    }
};
template<>
struct hash<Dynarmic::R4300::LocationDescriptor> {
    size_t operator()(const Dynarmic::R4300::LocationDescriptor& x) const noexcept {
        return std::hash<u64>()(x.UniqueHash());
    }
};
}  // namespace std

template<>
struct fmt::formatter<Dynarmic::R4300::LocationDescriptor> : fmt::formatter<std::string> {
    template<typename FormatContext>
    auto format(Dynarmic::R4300::LocationDescriptor descriptor, FormatContext& ctx) const {
        return formatter<std::string>::format(Dynarmic::R4300::ToString(descriptor), ctx);
    }
};
