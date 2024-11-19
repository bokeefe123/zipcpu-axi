// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vhello_world__pch.h"

//============================================================
// Constructors

Vhello_world::Vhello_world(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vhello_world__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vhello_world::Vhello_world(const char* _vcname__)
    : Vhello_world(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vhello_world::~Vhello_world() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vhello_world___024root___eval_debug_assertions(Vhello_world___024root* vlSelf);
#endif  // VL_DEBUG
void Vhello_world___024root___eval_static(Vhello_world___024root* vlSelf);
void Vhello_world___024root___eval_initial(Vhello_world___024root* vlSelf);
void Vhello_world___024root___eval_settle(Vhello_world___024root* vlSelf);
void Vhello_world___024root___eval(Vhello_world___024root* vlSelf);

void Vhello_world::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhello_world::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhello_world___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vhello_world___024root___eval_static(&(vlSymsp->TOP));
        Vhello_world___024root___eval_initial(&(vlSymsp->TOP));
        Vhello_world___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vhello_world___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vhello_world::eventsPending() { return false; }

uint64_t Vhello_world::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vhello_world::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vhello_world___024root___eval_final(Vhello_world___024root* vlSelf);

VL_ATTR_COLD void Vhello_world::final() {
    Vhello_world___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vhello_world::hierName() const { return vlSymsp->name(); }
const char* Vhello_world::modelName() const { return "Vhello_world"; }
unsigned Vhello_world::threads() const { return 1; }
void Vhello_world::prepareClone() const { contextp()->prepareClone(); }
void Vhello_world::atClone() const {
    contextp()->threadPoolpOnClone();
}
