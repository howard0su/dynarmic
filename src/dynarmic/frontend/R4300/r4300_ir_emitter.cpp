/* This file is part of the dynarmic project.
 * Copyright (c) 2016 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/frontend/R4300/r4300_ir_emitter.h"

#include <mcl/assert.hpp>

#include "dynarmic/ir/opcodes.h"

namespace Dynarmic::R4300 {

using Opcode = IR::Opcode;

u64 IREmitter::PC() const {
    return current_location->PC();
}

u64 IREmitter::AlignPC(size_t alignment) const {
    const u64 pc = PC();
    return static_cast<u64>(pc - pc % alignment);
}

void IREmitter::SetW(const Reg reg, const IR::U32& value) {
    if (reg == Reg::R0)
        return;
    Inst(Opcode::A64SetW, IR::Value(reg), value);
}

void IREmitter::SetX(const Reg reg, const IR::U64& value) {
    if (reg == Reg::R0)
        return;
    Inst(Opcode::A64SetX, IR::Value(reg), value);
}

IR::U32 IREmitter::GetW(Reg reg) {
    if (reg == Reg::R0)
        return Imm32(0);
    return Inst<IR::U32>(Opcode::A64GetW, IR::Value(reg));
}

IR::U64 IREmitter::GetX(Reg reg) {
    if (reg == Reg::R0)
        return Imm64(0);
    return Inst<IR::U64>(Opcode::A64GetX, IR::Value(reg));
}
}  // namespace Dynarmic::R4300
