// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VHELLO_WORLD__SYMS_H_
#define VERILATED_VHELLO_WORLD__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vhello_world.h"

// INCLUDE MODULE CLASSES
#include "Vhello_world___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vhello_world__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vhello_world* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vhello_world___024root         TOP;

    // CONSTRUCTORS
    Vhello_world__Syms(VerilatedContext* contextp, const char* namep, Vhello_world* modelp);
    ~Vhello_world__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
