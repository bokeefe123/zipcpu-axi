// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vudp.h for the primary calling header

#include "Vudp.h"
#include "Vudp__Syms.h"

//==========

VL_CTOR_IMP(Vudp) {
    Vudp__Syms* __restrict vlSymsp = __VlSymsp = new Vudp__Syms(this, name());
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vudp::__Vconfigure(Vudp__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vudp::~Vudp() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vudp::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vudp::eval\n"); );
    Vudp__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("udp.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vudp::_eval_initial_loop(Vudp__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("udp.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vudp::_sequent__TOP__1(Vudp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::_sequent__TOP__1\n"); );
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__t_offset;
    CData/*0:0*/ __Vdly__t_valid;
    CData/*0:0*/ __Vdly__t_last;
    CData/*1:0*/ __Vdly__r_offset;
    CData/*0:0*/ __Vdlyvset__buffer__v0;
    CData/*0:0*/ __Vdlyvset__buffer__v4;
    SData/*15:0*/ __Vdlyvval__buffer__v4;
    SData/*15:0*/ __Vdlyvval__buffer__v5;
    SData/*15:0*/ __Vdlyvval__buffer__v6;
    SData/*15:0*/ __Vdlyvval__buffer__v7;
    // Body
    __Vdly__r_offset = vlTOPp->r_offset;
    __Vdly__t_offset = vlTOPp->t_offset;
    __Vdlyvset__buffer__v0 = 0U;
    __Vdlyvset__buffer__v4 = 0U;
    __Vdly__t_last = vlTOPp->t_last;
    __Vdly__t_valid = vlTOPp->t_valid;
    if (vlTOPp->rst) {
        __Vdly__r_offset = 0U;
    }
    if (((IData)(vlTOPp->r_ready) & (IData)(vlTOPp->r_valid))) {
        if ((1U & (~ (IData)(vlTOPp->r_last)))) {
            __Vdly__r_offset = (3U & ((IData)(1U) + (IData)(vlTOPp->r_offset)));
        }
    }
    if (vlTOPp->rst) {
        __Vdly__t_offset = 0U;
    }
    if (((IData)(vlTOPp->t_valid) & (IData)(vlTOPp->t_ready))) {
        vlTOPp->t_data = vlTOPp->buffer[vlTOPp->t_offset];
        if ((1U & (~ (IData)(vlTOPp->t_last)))) {
            __Vdly__t_offset = (3U & ((IData)(1U) + (IData)(vlTOPp->t_offset)));
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__buffer__v0 = 1U;
    }
    if (((IData)(vlTOPp->r_ready) & (IData)(vlTOPp->r_valid))) {
        __Vdlyvval__buffer__v4 = vlTOPp->r_data;
        __Vdlyvset__buffer__v4 = 1U;
        __Vdlyvval__buffer__v5 = vlTOPp->buffer[3U];
        __Vdlyvval__buffer__v6 = vlTOPp->buffer[2U];
        __Vdlyvval__buffer__v7 = vlTOPp->buffer[1U];
    }
    if (vlTOPp->rst) {
        __Vdly__t_last = 0U;
    }
    if (vlTOPp->rst) {
        __Vdly__t_valid = 0U;
    }
    if (((IData)(vlTOPp->t_valid) & (IData)(vlTOPp->t_ready_stall))) {
        __Vdly__t_valid = 0U;
    }
    if (((((((((IData)(vlTOPp->t_offset) <= (IData)(vlTOPp->r_offset)) 
              & (IData)(vlTOPp->r_last)) & (~ (IData)(vlTOPp->r_valid))) 
            & (~ (IData)(vlTOPp->t_ready_stall))) & 
           (~ (IData)(vlTOPp->t_last))) & (~ (IData)(vlTOPp->t_valid))) 
         & (0U < (IData)(vlTOPp->r_offset)))) {
        __Vdly__t_valid = 1U;
        if (((IData)(vlTOPp->t_offset) == (IData)(vlTOPp->r_offset))) {
            __Vdly__t_last = 1U;
        }
    }
    if (__Vdlyvset__buffer__v0) {
        vlTOPp->buffer[3U] = 0U;
        vlTOPp->buffer[2U] = 0U;
        vlTOPp->buffer[1U] = 0U;
        vlTOPp->buffer[0U] = 0U;
    }
    if (__Vdlyvset__buffer__v4) {
        vlTOPp->buffer[3U] = __Vdlyvval__buffer__v4;
        vlTOPp->buffer[2U] = __Vdlyvval__buffer__v5;
        vlTOPp->buffer[1U] = __Vdlyvval__buffer__v6;
        vlTOPp->buffer[0U] = __Vdlyvval__buffer__v7;
    }
    vlTOPp->t_offset = __Vdly__t_offset;
    vlTOPp->r_offset = __Vdly__r_offset;
    vlTOPp->t_last = __Vdly__t_last;
    vlTOPp->t_valid = __Vdly__t_valid;
    vlTOPp->r_ready = vlTOPp->r_valid;
    vlTOPp->t_ready_stall = vlTOPp->t_ready;
}

void Vudp::_initial__TOP__2(Vudp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::_initial__TOP__2\n"); );
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->t_valid = 0U;
    vlTOPp->t_last = 0U;
    vlTOPp->r_offset = 0U;
    vlTOPp->t_offset = 0U;
    vlTOPp->t_ready_stall = 0U;
}

void Vudp::_eval(Vudp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::_eval\n"); );
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vudp::_eval_initial(Vudp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::_eval_initial\n"); );
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vudp::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::final\n"); );
    // Variables
    Vudp__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vudp::_eval_settle(Vudp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::_eval_settle\n"); );
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vudp::_change_request(Vudp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::_change_request\n"); );
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vudp::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((r_valid & 0xfeU))) {
        Verilated::overWidthError("r_valid");}
    if (VL_UNLIKELY((r_last & 0xfeU))) {
        Verilated::overWidthError("r_last");}
    if (VL_UNLIKELY((r_keep & 0xfeU))) {
        Verilated::overWidthError("r_keep");}
    if (VL_UNLIKELY((t_ready & 0xfeU))) {
        Verilated::overWidthError("t_ready");}
}
#endif  // VL_DEBUG

void Vudp::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vudp::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    r_valid = VL_RAND_RESET_I(1);
    r_ready = VL_RAND_RESET_I(1);
    r_data = VL_RAND_RESET_I(16);
    r_last = VL_RAND_RESET_I(1);
    r_keep = VL_RAND_RESET_I(1);
    t_valid = VL_RAND_RESET_I(1);
    t_ready = VL_RAND_RESET_I(1);
    t_data = VL_RAND_RESET_I(16);
    t_last = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            buffer[__Vi0] = VL_RAND_RESET_I(16);
    }}
    r_offset = VL_RAND_RESET_I(2);
    t_offset = VL_RAND_RESET_I(2);
    t_ready_stall = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
