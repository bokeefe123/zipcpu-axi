// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vudp.h for the primary calling header

#include "Vudp__pch.h"
#include "Vudp___024root.h"

VL_ATTR_COLD void Vudp___024root___eval_static(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vudp___024root___eval_initial__TOP(Vudp___024root* vlSelf);

VL_ATTR_COLD void Vudp___024root___eval_initial(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vudp___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vudp___024root___eval_initial__TOP(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.t_valid = 0U;
    vlSelfRef.t_last = 0U;
    vlSelfRef.r_offset = 0U;
    vlSelfRef.t_offset = 0U;
    vlSelfRef.t_ready_stall = 0U;
}

VL_ATTR_COLD void Vudp___024root___eval_final(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vudp___024root___eval_settle(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vudp___024root___dump_triggers__act(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vudp___024root___dump_triggers__nba(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vudp___024root___ctor_var_reset(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->r_valid = VL_RAND_RESET_I(1);
    vlSelf->r_ready = VL_RAND_RESET_I(1);
    vlSelf->r_data = VL_RAND_RESET_I(16);
    vlSelf->r_last = VL_RAND_RESET_I(1);
    vlSelf->r_keep = VL_RAND_RESET_I(1);
    vlSelf->t_valid = VL_RAND_RESET_I(1);
    vlSelf->t_ready = VL_RAND_RESET_I(1);
    vlSelf->t_data = VL_RAND_RESET_I(16);
    vlSelf->t_last = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->buffer[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->r_offset = VL_RAND_RESET_I(2);
    vlSelf->t_offset = VL_RAND_RESET_I(2);
    vlSelf->t_ready_stall = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
