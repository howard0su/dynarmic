/* This file is part of the dynarmic project.
 * Copyright (c) 2018 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include <catch2/catch_test_macros.hpp>

#include "./testenv.h"
#include "dynarmic/common/fp/fpsr.h"
#include "dynarmic/interface/exclusive_monitor.h"

#include "dynarmic/frontend/R4300/decoder/r4300.h"
#include "dynarmic/frontend/R4300/translate/impl/impl.h"

using namespace Dynarmic;

using namespace Dynarmic::R4300;

TEST_CASE("R4300: ADD", "[r4300]") {
    if (auto decoder = Decode<TranslatorVisitor>(0x00000000)) {
        printf("%p\n", decoder->get());
        return;
    }

    REQUIRE(false);
}