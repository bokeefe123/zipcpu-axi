// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vudp.h for the primary calling header

#include "Vudp__pch.h"
#include "Vudp___024root.h"

void Vudp___024root___eval_act(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vudp___024root___nba_sequent__TOP__0(Vudp___024root* vlSelf);

void Vudp___024root___eval_nba(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vudp___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vudp___024root___nba_sequent__TOP__0(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__t_valid;
    __Vdly__t_valid = 0;
    CData/*0:0*/ __Vdly__t_last;
    __Vdly__t_last = 0;
    CData/*1:0*/ __Vdly__r_offset;
    __Vdly__r_offset = 0;
    CData/*1:0*/ __Vdly__t_offset;
    __Vdly__t_offset = 0;
    CData/*0:0*/ __VdlySet__buffer__v0;
    __VdlySet__buffer__v0 = 0;
    SData/*15:0*/ __VdlyVal__buffer__v4;
    __VdlyVal__buffer__v4 = 0;
    CData/*0:0*/ __VdlySet__buffer__v4;
    __VdlySet__buffer__v4 = 0;
    SData/*15:0*/ __VdlyVal__buffer__v5;
    __VdlyVal__buffer__v5 = 0;
    SData/*15:0*/ __VdlyVal__buffer__v6;
    __VdlyVal__buffer__v6 = 0;
    SData/*15:0*/ __VdlyVal__buffer__v7;
    __VdlyVal__buffer__v7 = 0;
    // Body
    __VdlySet__buffer__v0 = 0U;
    __Vdly__t_offset = vlSelfRef.t_offset;
    __Vdly__r_offset = vlSelfRef.r_offset;
    __VdlySet__buffer__v4 = 0U;
    __Vdly__t_last = vlSelfRef.t_last;
    __Vdly__t_valid = vlSelfRef.t_valid;
    if (((IData)(vlSelfRef.r_ready) & (IData)(vlSelfRef.r_valid))) {
        if ((1U & (~ (IData)(vlSelfRef.r_last)))) {
            __Vdly__r_offset = (3U & ((IData)(1U) + (IData)(vlSelfRef.r_offset)));
        }
        __VdlyVal__buffer__v4 = vlSelfRef.r_data;
        __VdlySet__buffer__v4 = 1U;
        __VdlyVal__buffer__v5 = vlSelfRef.buffer[3U];
        __VdlyVal__buffer__v6 = vlSelfRef.buffer[2U];
        __VdlyVal__buffer__v7 = vlSelfRef.buffer[1U];
    }
    if (((IData)(vlSelfRef.t_valid) & (IData)(vlSelfRef.t_ready_stall))) {
        __Vdly__t_valid = 0U;
    }
    if (vlSelfRef.reset) {
        __Vdly__t_valid = 0U;
        __Vdly__t_last = 0U;
        __Vdly__r_offset = 0U;
        __Vdly__t_offset = 0U;
        vlSelfRef.reset = 0U;
        __VdlySet__buffer__v0 = 1U;
    }
    if (((((((((IData)(vlSelfRef.t_offset) <= (IData)(vlSelfRef.r_offset)) 
              & (IData)(vlSelfRef.r_last)) & (~ (IData)(vlSelfRef.r_valid))) 
            & (~ (IData)(vlSelfRef.t_ready_stall))) 
           & (~ (IData)(vlSelfRef.t_last))) & (~ (IData)(vlSelfRef.t_valid))) 
         & (0U < (IData)(vlSelfRef.r_offset)))) {
        __Vdly__t_valid = 1U;
        if (((IData)(vlSelfRef.t_offset) == (IData)(vlSelfRef.r_offset))) {
            __Vdly__t_last = 1U;
        }
    }
    if (((IData)(vlSelfRef.t_valid) & (IData)(vlSelfRef.t_ready))) {
        vlSelfRef.t_data = vlSelfRef.buffer[vlSelfRef.t_offset];
        if ((1U & (~ (IData)(vlSelfRef.t_last)))) {
            __Vdly__t_offset = (3U & ((IData)(1U) + (IData)(vlSelfRef.t_offset)));
        }
    }
    vlSelfRef.r_offset = __Vdly__r_offset;
    vlSelfRef.t_last = __Vdly__t_last;
    vlSelfRef.t_valid = __Vdly__t_valid;
    vlSelfRef.t_offset = __Vdly__t_offset;
    if (__VdlySet__buffer__v0) {
        vlSelfRef.buffer[3U] = 0U;
        vlSelfRef.buffer[2U] = 0U;
        vlSelfRef.buffer[1U] = 0U;
        vlSelfRef.buffer[0U] = 0U;
    }
    if (__VdlySet__buffer__v4) {
        vlSelfRef.buffer[3U] = __VdlyVal__buffer__v4;
        vlSelfRef.buffer[2U] = __VdlyVal__buffer__v5;
        vlSelfRef.buffer[1U] = __VdlyVal__buffer__v6;
        vlSelfRef.buffer[0U] = __VdlyVal__buffer__v7;
    }
    vlSelfRef.r_ready = vlSelfRef.r_valid;
    vlSelfRef.t_ready_stall = vlSelfRef.t_ready;
}

void Vudp___024root___eval_triggers__act(Vudp___024root* vlSelf);

bool Vudp___024root___eval_phase__act(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vudp___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vudp___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vudp___024root___eval_phase__nba(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vudp___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vudp___024root___dump_triggers__nba(Vudp___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vudp___024root___dump_triggers__act(Vudp___024root* vlSelf);
#endif  // VL_DEBUG

void Vudp___024root___eval(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vudp___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("udp.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vudp___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("udp.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vudp___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vudp___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vudp___024root___eval_debug_assertions(Vudp___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.r_valid & 0xfeU))) {
        Verilated::overWidthError("r_valid");}
    if (VL_UNLIKELY((vlSelfRef.r_last & 0xfeU))) {
        Verilated::overWidthError("r_last");}
    if (VL_UNLIKELY((vlSelfRef.r_keep & 0xfeU))) {
        Verilated::overWidthError("r_keep");}
    if (VL_UNLIKELY((vlSelfRef.t_ready & 0xfeU))) {
        Verilated::overWidthError("t_ready");}
}
#endif  // VL_DEBUG
