// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vudp.h for the primary calling header

#include "Vudp__pch.h"
#include "Vudp__Syms.h"
#include "Vudp___024root.h"

void Vudp___024root___ctor_var_reset(Vudp___024root* vlSelf);

Vudp___024root::Vudp___024root(Vudp__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vudp___024root___ctor_var_reset(this);
}

void Vudp___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vudp___024root::~Vudp___024root() {
}
