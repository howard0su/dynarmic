/* This file is part of the dynarmic project.
 * Copyright (c) 2016 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <optional>

#include <mcl/stdint.hpp>

#include "dynarmic/frontend/R4300/r4300_location_descriptor.h"
#include "dynarmic/frontend/R4300/r4300_types.h"
#include "dynarmic/interface/R4300/config.h"
#include "dynarmic/ir/ir_emitter.h"
#include "dynarmic/ir/value.h"

namespace Dynarmic::R4300 {

/**
 * Convenience class to construct a basic block of the intermediate representation.
 * `block` is the resulting block.
 * The user of this class updates `current_location` as appropriate.
 */
class IREmitter : public IR::IREmitter {
public:
    explicit IREmitter(IR::Block& block)
            : IR::IREmitter(block) {}
    explicit IREmitter(IR::Block& block, LocationDescriptor descriptor)
            : IR::IREmitter(block), current_location(descriptor) {}

    std::optional<LocationDescriptor> current_location;

    u64 PC() const;
    u64 AlignPC(size_t alignment) const;

    IR::U32 GetW(Reg source_reg);
    IR::U64 GetX(Reg source_reg);
    void SetW(Reg dest_reg, const IR::U32& value);
    void SetX(Reg dest_reg, const IR::U64& value);

};

}  // namespace Dynarmic::R4300
