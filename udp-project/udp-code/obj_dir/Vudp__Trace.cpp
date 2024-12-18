// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vudp__Syms.h"


//======================

void Vudp::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vudp* t = (Vudp*)userthis;
    Vudp__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vudp::traceChgThis(Vudp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vudp::traceChgThis__2(Vudp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->clk));
        vcdp->chgBit(oldp+1,(vlTOPp->rst));
        vcdp->chgBit(oldp+2,(vlTOPp->r_valid));
        vcdp->chgBit(oldp+3,(vlTOPp->r_ready));
        vcdp->chgSData(oldp+4,(vlTOPp->r_data),16);
        vcdp->chgBit(oldp+5,(vlTOPp->r_last));
        vcdp->chgBit(oldp+6,(vlTOPp->r_keep));
        vcdp->chgBit(oldp+7,(vlTOPp->t_valid));
        vcdp->chgBit(oldp+8,(vlTOPp->t_ready));
        vcdp->chgSData(oldp+9,(vlTOPp->t_data),16);
        vcdp->chgBit(oldp+10,(vlTOPp->t_last));
        vcdp->chgSData(oldp+11,(vlTOPp->buffer[0]),16);
        vcdp->chgSData(oldp+12,(vlTOPp->buffer[1]),16);
        vcdp->chgSData(oldp+13,(vlTOPp->buffer[2]),16);
        vcdp->chgSData(oldp+14,(vlTOPp->buffer[3]),16);
        vcdp->chgCData(oldp+15,(vlTOPp->r_offset),2);
        vcdp->chgCData(oldp+16,(vlTOPp->t_offset),2);
        vcdp->chgBit(oldp+17,(vlTOPp->t_ready_stall));
    }
}
