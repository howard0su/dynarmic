#include "dynarmic/frontend/R4300/translate/impl/impl.h"

#include <mcl/bit/bit_count.hpp>
#include <mcl/bit/bit_field.hpp>
#include <mcl/bit/rotate.hpp>

#include "dynarmic/ir/terminal.h"

namespace Dynarmic::R4300 {

bool TranslatorVisitor::InterpretThisInstruction() {
    ir.SetTerm(IR::Term::Interpret(*ir.current_location));
    return false;
}


IR::UAny TranslatorVisitor::I(size_t bitsize, u64 value) {
    switch (bitsize) {
    case 8:
        return ir.Imm8(static_cast<u8>(value));
    case 16:
        return ir.Imm16(static_cast<u16>(value));
    case 32:
        return ir.Imm32(static_cast<u32>(value));
    case 64:
        return ir.Imm64(value);
    default:
        ASSERT_FALSE("Imm - get: Invalid bitsize");
    }
}

IR::UAny TranslatorVisitor::X(size_t bitsize, Reg reg) {
    switch (bitsize) {
    case 8:
        return ir.LeastSignificantByte(ir.GetW(reg));
    case 16:
        return ir.LeastSignificantHalf(ir.GetW(reg));
    case 32:
        return ir.GetW(reg);
    case 64:
        return ir.GetX(reg);
    default:
        ASSERT_FALSE("X - get: Invalid bitsize");
    }
}

void TranslatorVisitor::X(size_t bitsize, Reg reg, IR::U32U64 value) {
    switch (bitsize) {
    case 32:
        ir.SetW(reg, value);
        return;
    case 64:
        ir.SetX(reg, value);
        return;
    default:
        ASSERT_FALSE("X - set: Invalid bitsize");
    }
}
}