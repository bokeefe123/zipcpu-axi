// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhello_world.h for the primary calling header

#ifndef VERILATED_VHELLO_WORLD___024ROOT_H_
#define VERILATED_VHELLO_WORLD___024ROOT_H_  // guard

#include "verilated.h"


class Vhello_world__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vhello_world___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vhello_world__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vhello_world___024root(Vhello_world__Syms* symsp, const char* v__name);
    ~Vhello_world___024root();
    VL_UNCOPYABLE(Vhello_world___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
