/* This file is part of the dynarmic project.
 * Copyright (c) 2018 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <optional>

#include "dynarmic/frontend/R4300/r4300_ir_emitter.h"
#include "dynarmic/frontend/R4300/r4300_location_descriptor.h"
#include "dynarmic/frontend/R4300/r4300_types.h"
#include "dynarmic/frontend/R4300/translate/r4300_translate.h"
#include "dynarmic/frontend/imm.h"

namespace Dynarmic::R4300 {

struct TranslatorVisitor final {
    using instruction_return_type = bool;

    explicit TranslatorVisitor(IR::Block& block, LocationDescriptor descriptor, TranslationOptions options)
            : ir(block, descriptor), options(std::move(options)) {}

    R4300::IREmitter ir;
    TranslationOptions options;

    bool InterpretThisInstruction();
    bool UnpredictableInstruction();
    bool DecodeError();
    bool ReservedValue();
    bool UnallocatedEncoding();
    bool RaiseException(Exception exception);

    IR::UAny I(size_t bitsize, u64 value);
    IR::UAny X(size_t bitsize, Reg reg);
    void X(size_t bitsize, Reg reg, IR::U32U64 value);

/* J_TYPE */
    bool J(Imm<26> imm12)
    {
        return false;
    }

    bool JAL(Imm<26> imm12)
    {
        return false;
    }

/* I_TYPE */
bool BEQ(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool BNE(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool BLEZ(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool BGTZ(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool ADDI(Reg rs, Reg rt, Imm<16> imm);
bool ADDIU(Reg rs, Reg rt, Imm<16> imm);

bool SLTI(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SLTIU(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool ANDI(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool ORI(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool XORI(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LUI(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool BEQL(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool BNEL(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool BLEZL(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool BGTZL(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool DADDI(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool DADDIU(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LDL(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LDR(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LB(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LH(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LWL(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LW(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LBU(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LHU(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LWR(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LWU(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SB(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SH(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SWL(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SW(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SBU(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SHU(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SWR(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool CACHE(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LL(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LWC1(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LLD(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LDC1(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LDC2(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool LD(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SC(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SWC1(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool DBG_Bkpt(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SCD(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SDC1(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SDC2(Reg rs, Reg rt, Imm<16> imm)
{return false;}

bool SD(Reg rs, Reg rt, Imm<16> imm)
{return false;}

/* R_TYPE*/
bool SLL(Reg rt, Reg rd, Imm<5> imm);

bool SRL(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SRA(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SLLV(Reg rs, Reg rt, Reg rd);

bool SRLV(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SRAV(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool JR(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool JALR(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SYSCALL(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool BREAK(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SYNC(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool MFHI(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool MTHI(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool MFLO(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool MTLO(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSLLV(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSRLV(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSRAV(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool MULT(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool MULTU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DIV(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DIVU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DMULT(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DMULTU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DDIV(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DDIVU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool ADD(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool ADDU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SUB(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SUBU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool AND(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool OR(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool XOR(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool NOR(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SLT(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool SLTU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DADD(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DADDU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSUB(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSUBU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool TGE(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool TGEU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool TLT(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool TLTU(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool TEQ(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool TNE(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSLL(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSRL(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSRA(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSLL32(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSRL32(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }
bool DSRA32(Reg rs, Reg rt, Reg rd, Imm<5> imm)
{return false; }

};

inline std::optional<size_t> FPGetDataSize(Imm<2> type) {
    switch (type.ZeroExtend()) {
    case 0b00:
        return 32;
    case 0b01:
        return 64;
    case 0b11:
        return 16;
    }
    return std::nullopt;
}

}  // namespace Dynarmic::R4300
