// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vudp__Syms.h"


//======================

void Vudp::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vudp::traceInit, &Vudp::traceFull, &Vudp::traceChg, this);
}
void Vudp::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vudp* t = (Vudp*)userthis;
    Vudp__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vudp::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vudp* t = (Vudp*)userthis;
    Vudp__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vudp::traceInitThis(Vudp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vudp::traceFullThis(Vudp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vudp::traceInitThis__1(Vudp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (false && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"clk", false,-1);
        vcdp->declBit(c+2,"rst", false,-1);
        vcdp->declBit(c+3,"r_valid", false,-1);
        vcdp->declBit(c+4,"r_ready", false,-1);
        vcdp->declBus(c+5,"r_data", false,-1, 15,0);
        vcdp->declBit(c+6,"r_last", false,-1);
        vcdp->declBit(c+7,"r_keep", false,-1);
        vcdp->declBit(c+8,"t_valid", false,-1);
        vcdp->declBit(c+9,"t_ready", false,-1);
        vcdp->declBus(c+10,"t_data", false,-1, 15,0);
        vcdp->declBit(c+11,"t_last", false,-1);
        {int i; for (i=0; i<4; i++) {
                vcdp->declBus(c+12+i*1,"buffer", true,(i+0), 15,0);}}
        vcdp->declBus(c+16,"r_offset", false,-1, 1,0);
        vcdp->declBus(c+17,"t_offset", false,-1, 1,0);
        vcdp->declBit(c+18,"t_ready_stall", false,-1);
        vcdp->declBit(c+1,"udp clk", false,-1);
        vcdp->declBit(c+2,"udp rst", false,-1);
        vcdp->declBit(c+3,"udp r_valid", false,-1);
        vcdp->declBit(c+4,"udp r_ready", false,-1);
        vcdp->declBus(c+5,"udp r_data", false,-1, 15,0);
        vcdp->declBit(c+6,"udp r_last", false,-1);
        vcdp->declBit(c+7,"udp r_keep", false,-1);
        vcdp->declBit(c+8,"udp t_valid", false,-1);
        vcdp->declBit(c+9,"udp t_ready", false,-1);
        vcdp->declBus(c+10,"udp t_data", false,-1, 15,0);
        vcdp->declBit(c+11,"udp t_last", false,-1);
        {int i; for (i=0; i<4; i++) {
                vcdp->declBus(c+12+i*1,"udp buffer", true,(i+0), 15,0);}}
        vcdp->declBus(c+16,"udp r_offset", false,-1, 1,0);
        vcdp->declBus(c+17,"udp t_offset", false,-1, 1,0);
        vcdp->declBit(c+18,"udp t_ready_stall", false,-1);
        vcdp->declBus(c+19,"udp DATA_WIDTH", false,-1, 1,0);
    }
}

void Vudp::traceFullThis__1(Vudp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vudp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(oldp+0,(vlTOPp->clk));
        vcdp->fullBit(oldp+1,(vlTOPp->rst));
        vcdp->fullBit(oldp+2,(vlTOPp->r_valid));
        vcdp->fullBit(oldp+3,(vlTOPp->r_ready));
        vcdp->fullSData(oldp+4,(vlTOPp->r_data),16);
        vcdp->fullBit(oldp+5,(vlTOPp->r_last));
        vcdp->fullBit(oldp+6,(vlTOPp->r_keep));
        vcdp->fullBit(oldp+7,(vlTOPp->t_valid));
        vcdp->fullBit(oldp+8,(vlTOPp->t_ready));
        vcdp->fullSData(oldp+9,(vlTOPp->t_data),16);
        vcdp->fullBit(oldp+10,(vlTOPp->t_last));
        vcdp->fullSData(oldp+11,(vlTOPp->buffer[0]),16);
        vcdp->fullSData(oldp+12,(vlTOPp->buffer[1]),16);
        vcdp->fullSData(oldp+13,(vlTOPp->buffer[2]),16);
        vcdp->fullSData(oldp+14,(vlTOPp->buffer[3]),16);
        vcdp->fullCData(oldp+15,(vlTOPp->r_offset),2);
        vcdp->fullCData(oldp+16,(vlTOPp->t_offset),2);
        vcdp->fullBit(oldp+17,(vlTOPp->t_ready_stall));
        vcdp->fullCData(oldp+18,(3U),2);
    }
}
