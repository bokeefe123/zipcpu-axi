// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vudp.h for the primary calling header

#ifndef VERILATED_VUDP___024ROOT_H_
#define VERILATED_VUDP___024ROOT_H_  // guard

#include "verilated.h"


class Vudp__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vudp___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(r_valid,0,0);
    VL_OUT8(r_ready,0,0);
    VL_IN8(r_last,0,0);
    VL_IN8(r_keep,0,0);
    VL_OUT8(t_valid,0,0);
    VL_IN8(t_ready,0,0);
    VL_OUT8(t_last,0,0);
    CData/*1:0*/ udp__DOT__r_offset;
    CData/*1:0*/ udp__DOT__t_offset;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(r_data,15,0);
    VL_OUT16(t_data,15,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 4> udp__DOT__buffer;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vudp__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vudp___024root(Vudp__Syms* symsp, const char* v__name);
    ~Vudp___024root();
    VL_UNCOPYABLE(Vudp___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
