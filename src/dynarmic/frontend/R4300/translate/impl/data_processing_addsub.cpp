
#include "dynarmic/frontend/R4300/translate/impl/impl.h"

namespace Dynarmic::R4300 {
    bool TranslatorVisitor::ADDI(Reg rs, Reg rt, Imm<16> imm)
    {
        if (rt == Reg::R0)
            return true;

        
        return false;
    }


    bool TranslatorVisitor::ADDIU(Reg rs, Reg rt, Imm<16> imm)
    {
        if (rt == Reg::R0)
            return true;

        return false;
    }

}
