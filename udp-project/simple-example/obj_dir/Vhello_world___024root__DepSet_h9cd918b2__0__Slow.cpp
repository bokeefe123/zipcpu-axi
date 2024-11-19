// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello_world.h for the primary calling header

#include "Vhello_world__pch.h"
#include "Vhello_world___024root.h"

VL_ATTR_COLD void Vhello_world___024root___eval_static(Vhello_world___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vhello_world___024root___eval_initial__TOP(Vhello_world___024root* vlSelf);

VL_ATTR_COLD void Vhello_world___024root___eval_initial(Vhello_world___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vhello_world___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vhello_world___024root___eval_initial__TOP(Vhello_world___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("Hello, Verilator!\n",0);
    VL_FINISH_MT("hello_world.v", 4, "");
}

VL_ATTR_COLD void Vhello_world___024root___eval_final(Vhello_world___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vhello_world___024root___eval_settle(Vhello_world___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello_world___024root___dump_triggers__act(Vhello_world___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello_world___024root___dump_triggers__nba(Vhello_world___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhello_world___024root___ctor_var_reset(Vhello_world___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
