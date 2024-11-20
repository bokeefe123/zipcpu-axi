// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vudp__Syms.h"


void Vudp___024root__trace_chg_0_sub_0(Vudp___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vudp___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root__trace_chg_0\n"); );
    // Init
    Vudp___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vudp___024root*>(voidSelf);
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vudp___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vudp___024root__trace_chg_0_sub_0(Vudp___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelfRef.udp__DOT__buffer[0]),16);
        bufp->chgSData(oldp+1,(vlSelfRef.udp__DOT__buffer[1]),16);
        bufp->chgSData(oldp+2,(vlSelfRef.udp__DOT__buffer[2]),16);
        bufp->chgSData(oldp+3,(vlSelfRef.udp__DOT__buffer[3]),16);
        bufp->chgCData(oldp+4,(vlSelfRef.udp__DOT__r_offset),2);
        bufp->chgCData(oldp+5,(vlSelfRef.udp__DOT__t_offset),2);
    }
    bufp->chgBit(oldp+6,(vlSelfRef.clk));
    bufp->chgBit(oldp+7,(vlSelfRef.r_valid));
    bufp->chgBit(oldp+8,(vlSelfRef.r_ready));
    bufp->chgSData(oldp+9,(vlSelfRef.r_data),16);
    bufp->chgBit(oldp+10,(vlSelfRef.r_last));
    bufp->chgBit(oldp+11,(vlSelfRef.r_keep));
    bufp->chgBit(oldp+12,(vlSelfRef.t_valid));
    bufp->chgBit(oldp+13,(vlSelfRef.t_ready));
    bufp->chgSData(oldp+14,(vlSelfRef.t_data),16);
    bufp->chgBit(oldp+15,(vlSelfRef.t_last));
}

void Vudp___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp___024root__trace_cleanup\n"); );
    // Init
    Vudp___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vudp___024root*>(voidSelf);
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
