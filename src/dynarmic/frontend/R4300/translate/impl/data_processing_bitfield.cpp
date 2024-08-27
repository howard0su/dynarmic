
#include "dynarmic/frontend/R4300/translate/impl/impl.h"

namespace Dynarmic::R4300 {
    bool TranslatorVisitor::SLL(Reg rt, Reg rd, Imm<5> imm)
    {
        const auto src = X(32, rt);
        const auto result = ir.LogicalShiftLeftMasked(src, ir.Imm32(imm.ZeroExtend<u32>()));
        const auto extended = ir.SignExtendWordToLong(result);
        X(64, rd, extended);
        return true;
    }

    bool TranslatorVisitor::SLLV(Reg rs, Reg rt, Reg rd)
    {
        const auto src = X(32, rs);
        const auto move = ir.And(X(32, rt), ir.Imm32(0xF));
        const auto result = ir.LogicalShiftLeftMasked(src, move);
        const auto extended = ir.SignExtendWordToLong(result);
        X(64, rd, extended);

        return false;
    }
}