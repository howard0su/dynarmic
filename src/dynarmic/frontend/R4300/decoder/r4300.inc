/*
R4300 Instruction Decoding:

*/

/*
    CPU: Instructions encoded by opcode field.
    31---------26---------------------------------------------------0
    |  opcode   |                                                   |
    ------6----------------------------------------------------------
    |--000--|--001--|--010--|--011--|--100--|--101--|--110--|--111--| lo
000 | *1    | *2    | J     | JAL   | BEQ   | BNE   | BLEZ  | BGTZ  |
001 | ADDI  | ADDIU | SLTI  | SLTIU | ANDI  | ORI   | XORI  | LUI   |
010 | *3    | *4    |  ---  |  ---  | BEQL  | BNEL  | BLEZL | BGTZL |
011 | DADDI |DADDIU | LDL   | LDR   | Patch |SRHackU|SRHackO|SRHackN|
100 | LB    | LH    | LWL   | LW    | LBU   | LHU   | LWR   | LWU   |
101 | SB    | SH    | SWL   | SW    | SDL   | SDR   | SWR   | CACHE |
110 | LL    | LWC1  |  ---  |  ---  | LLD   | LDC1  | LDC2  | LD    |
111 | SC    | SWC1  | DBkpt |  ---  | SCD   | SDC1  | SDC2  | SD    |
 hi |-------|-------|-------|-------|-------|-------|-------|-------|
     *1 = SPECIAL, see SPECIAL list    *2 = REGIMM, see REGIMM list
     *3 = COP0                         *4 = COP1
	// Patch, SRHackU, SRHackO, SRHackN are all optimisation hacks
	// DBkpt is a debugging breakpoint


*/

INST(J,                 "J",                 "000010iiiiiiiiiiiiiiiiiiiiiiiiii")
INST(JAL,               "JAL",               "000011iiiiiiiiiiiiiiiiiiiiiiiiii")

INST(BEQ,               "BEQ",               "000100ssssstttttiiiiiiiiiiiiiiii")
INST(BNE,               "BNE",               "000101ssssstttttiiiiiiiiiiiiiiii")
INST(BLEZ,              "BLEZ",              "000110ssssstttttiiiiiiiiiiiiiiii")
INST(BGTZ,              "BGTZ",              "000111ssssstttttiiiiiiiiiiiiiiii")

INST(ADDI,                 "ADDI",           "001000ssssstttttiiiiiiiiiiiiiiii")
INST(ADDIU,                "ADDIU",          "001001ssssstttttiiiiiiiiiiiiiiii")
INST(SLTI,                 "SLTI",           "001010ssssstttttiiiiiiiiiiiiiiii")
INST(SLTIU,                "SLTIU",          "001011ssssstttttiiiiiiiiiiiiiiii")
INST(ANDI,                 "ANDI",           "001100ssssstttttiiiiiiiiiiiiiiii")
INST(ORI,                  "ORI",            "001101ssssstttttiiiiiiiiiiiiiiii")
INST(XORI,                 "XORI",           "001110ssssstttttiiiiiiiiiiiiiiii")
INST(LUI,                  "LUI",            "001111ssssstttttiiiiiiiiiiiiiiii")

INST(BEQL,               "BEQL",             "010100ssssstttttiiiiiiiiiiiiiiii")
INST(BNEL,               "BNEL",             "010101ssssstttttiiiiiiiiiiiiiiii")
INST(BLEZL,              "BLEZL",            "010110ssssstttttiiiiiiiiiiiiiiii")
INST(BGTZL,              "BGTZL",            "010111ssssstttttiiiiiiiiiiiiiiii")

INST(DADDI,                 "DADDI",         "011000ssssstttttiiiiiiiiiiiiiiii")
INST(DADDIU,                "DADDIU",        "011001ssssstttttiiiiiiiiiiiiiiii")
INST(LDL,                "LDL",              "011010ssssstttttiiiiiiiiiiiiiiii")
INST(LDR,                "LDR",              "011011ssssstttttiiiiiiiiiiiiiiii")

INST(LB,                "LB",                 "100000ssssstttttiiiiiiiiiiiiiiii")
INST(LH,                "LH",                 "100001ssssstttttiiiiiiiiiiiiiiii")
INST(LWL,               "LWL",                "100010ssssstttttiiiiiiiiiiiiiiii")
INST(LW,                "LW",                 "100011ssssstttttiiiiiiiiiiiiiiii")
INST(LBU,               "LBU",                "100100ssssstttttiiiiiiiiiiiiiiii")
INST(LHU,               "LHU",                "100101ssssstttttiiiiiiiiiiiiiiii")
INST(LWR,               "LWR",                "100110ssssstttttiiiiiiiiiiiiiiii")
INST(LWU,               "LWU",                "100111ssssstttttiiiiiiiiiiiiiiii")

INST(SB,                "SB",                 "101000ssssstttttiiiiiiiiiiiiiiii")
INST(SH,                "SH",                 "101001ssssstttttiiiiiiiiiiiiiiii")
INST(SWL,               "SWL",                "101010ssssstttttiiiiiiiiiiiiiiii")
INST(SW,                "SW",                 "101011ssssstttttiiiiiiiiiiiiiiii")
INST(SBU,               "SBU",                "101100ssssstttttiiiiiiiiiiiiiiii")
INST(SHU,               "SHU",                "101101ssssstttttiiiiiiiiiiiiiiii")
INST(SWR,               "SWR",                "101110ssssstttttiiiiiiiiiiiiiiii")
INST(CACHE,             "CACHE",              "101111ssssstttttiiiiiiiiiiiiiiii")

INST(LL,                 "LL",                 "110000ssssstttttiiiiiiiiiiiiiiii")
INST(LWC1,               "LWC1",               "110001ssssstttttiiiiiiiiiiiiiiii")
INST(LLD,                "LLD",                "110100ssssstttttiiiiiiiiiiiiiiii")
INST(LDC1,               "LDC1",               "110101ssssstttttiiiiiiiiiiiiiiii")
INST(LDC2,               "LDC2",               "110110ssssstttttiiiiiiiiiiiiiiii")
INST(LD,                 "LD",                 "110111ssssstttttiiiiiiiiiiiiiiii")
	
INST(SC,                 "SC",               "111000ssssstttttiiiiiiiiiiiiiiii")
INST(SWC1,               "SWC1",             "111001ssssstttttiiiiiiiiiiiiiiii")
INST(DBG_Bkpt,           "DBG_Bkpt",         "111010ssssstttttiiiiiiiiiiiiiiii")
INST(SCD,                "SCD",              "111100ssssstttttiiiiiiiiiiiiiiii")
INST(SDC1,               "SDC1",             "111101ssssstttttiiiiiiiiiiiiiiii")
INST(SDC2,               "SDC2",             "111110ssssstttttiiiiiiiiiiiiiiii")
INST(SD,                 "SD",               "111111ssssstttttiiiiiiiiiiiiiiii")

/*
    SPECIAL: Instr. encoded by function field when opcode field = SPECIAL.
    31---------26------------------------------------------5--------0
    | = SPECIAL |                                         | function|
    ------6----------------------------------------------------6-----
    |--000--|--001--|--010--|--011--|--100--|--101--|--110--|--111--| lo
000 | SLL   |  ---  | SRL   | SRA   | SLLV  |  ---  | SRLV  | SRAV  |
001 | JR    | JALR  |  ---  |  ---  |SYSCALL| BREAK |  ---  | SYNC  |
010 | MFHI  | MTHI  | MFLO  | MTLO  | DSLLV |  ---  | DSRLV | DSRAV |
011 | MULT  | MULTU | DIV   | DIVU  | DMULT | DMULTU| DDIV  | DDIVU |
100 | ADD   | ADDU  | SUB   | SUBU  | AND   | OR    | XOR   | NOR   |
101 |  ---  |  ---  | SLT   | SLTU  | DADD  | DADDU | DSUB  | DSUBU |
110 | TGE   | TGEU  | TLT   | TLTU  | TEQ   |  ---  | TNE   |  ---  |
111 | DSLL  |  ---  | DSRL  | DSRA  |DSLL32 |  ---  |DSRL32 |DSRA32 |
 hi |-------|-------|-------|-------|-------|-------|-------|-------|
*/

	
INST(SLL,                       "SLL",                  "00000000000tttttdddddiiiii000000")
INST(SRL,                       "SRL",                  "000000ssssstttttdddddiiiii000010")
INST(SRA,                       "SRA",                  "000000ssssstttttdddddiiiii000011")
INST(SLLV,                      "SLLV",                 "000000ssssstttttddddd00000000100")
INST(SRLV,                      "SRLV",                 "000000ssssstttttdddddiiiii000110")
INST(SRAV,                      "SRA",                  "000000ssssstttttdddddiiiii000111")
	
INST(JR,                        "JR",                   "000000ssssstttttdddddiiiii001000")
INST(JALR,                      "JALR",                 "000000ssssstttttdddddiiiii001001")
INST(SYSCALL,                   "SYSCALL",              "000000ssssstttttdddddiiiii001100")
INST(BREAK,                     "BREAK",                "000000ssssstttttdddddiiiii001101")
INST(SYNC,                      "SYN",                  "000000ssssstttttdddddiiiii001111")
	
INST(MFHI,                      "MFHI",                 "000000ssssstttttdddddiiiii010000")
INST(MTHI,                      "MTHI",                 "000000ssssstttttdddddiiiii010001")
INST(MFLO,                      "MFLO",                 "000000ssssstttttdddddiiiii010010")
INST(MTLO,                      "MTLO",                 "000000ssssstttttdddddiiiii010011")
INST(DSLLV,                     "DSLLV",                "000000ssssstttttdddddiiiii010100")
INST(DSRLV,                     "DSRLV",                "000000ssssstttttdddddiiiii010110")
INST(DSRAV,                     "DSRA",                 "000000ssssstttttdddddiiiii010111")
	
INST(MULT,                      "MULT",                 "000000ssssstttttdddddiiiii011000")
INST(MULTU,                     "MULTU",                "000000ssssstttttdddddiiiii011001")
INST(DIV,                       "DIV",                  "000000ssssstttttdddddiiiii011010")
INST(DIVU,                      "DIVU",                 "000000ssssstttttdddddiiiii011011")
INST(DMULT,                     "DMULT",                "000000ssssstttttdddddiiiii011100")
INST(DMULTU,                    "DMULTU",               "000000ssssstttttdddddiiiii011101")
INST(DDIV,                      "DDIV",                 "000000ssssstttttdddddiiiii011110")
INST(DDIVU,                     "DDIV",                 "000000ssssstttttdddddiiiii011111")
	
INST(ADD,                       "ADD",                  "000000ssssstttttdddddiiiii100000")
INST(ADDU,                      "ADDU",                 "000000ssssstttttdddddiiiii100001")
INST(SUB,                       "SUB",                  "000000ssssstttttdddddiiiii100010")
INST(SUBU,                      "SUBU",                 "000000ssssstttttdddddiiiii100011")
INST(AND,                       "AND",                  "000000ssssstttttdddddiiiii100100")
INST(OR,                        "OR",                   "000000ssssstttttdddddiiiii100101")
INST(XOR,                       "XOR",                  "000000ssssstttttdddddiiiii100110")
INST(NOR,                       "NO",                   "000000ssssstttttdddddiiiii100111")
	
INST(SLT,                       "SLT",                  "000000ssssstttttdddddiiiii101010")
INST(SLTU,                      "SLTU",                 "000000ssssstttttdddddiiiii101011")
INST(DADD,                      "DADD",                 "000000ssssstttttdddddiiiii101100")
INST(DADDU,                     "DADDU",                "000000ssssstttttdddddiiiii101101")
INST(DSUB,                      "DSUB",                 "000000ssssstttttdddddiiiii101110")
INST(DSUBU,                     "DSUB",                 "000000ssssstttttdddddiiiii101111")
	
INST(TGE,                       "TGE",                  "000000ssssstttttdddddiiiii110000")
INST(TGEU,                      "TGEU",                 "000000ssssstttttdddddiiiii110001")
INST(TLT,                       "TLT",                  "000000ssssstttttdddddiiiii110010")
INST(TLTU,                      "TLTU",                 "000000ssssstttttdddddiiiii110011")
INST(TEQ,                       "TEQ",                  "000000ssssstttttdddddiiiii110100")
INST(TNE,                       "TNE",                  "000000ssssstttttdddddiiiii110110")
	
INST(DSLL,                      "DSLL",                 "000000ssssstttttdddddiiiii111000")
INST(DSRL,                      "DSRL",                 "000000ssssstttttdddddiiiii111010")
INST(DSRA,                      "DSRA",                 "000000ssssstttttdddddiiiii111011")
INST(DSLL32,                    "DSLL32",               "000000ssssstttttdddddiiiii111100")
INST(DSRL32,                    "DSRL32",               "000000ssssstttttdddddiiiii111110")
INST(DSRA32,                    "DSRA32",               "000000ssssstttttdddddiiiii111111")

