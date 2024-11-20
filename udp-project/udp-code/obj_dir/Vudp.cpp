// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vudp__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vudp::Vudp(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vudp__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , r_valid{vlSymsp->TOP.r_valid}
    , r_ready{vlSymsp->TOP.r_ready}
    , r_last{vlSymsp->TOP.r_last}
    , r_keep{vlSymsp->TOP.r_keep}
    , t_valid{vlSymsp->TOP.t_valid}
    , t_ready{vlSymsp->TOP.t_ready}
    , t_last{vlSymsp->TOP.t_last}
    , r_data{vlSymsp->TOP.r_data}
    , t_data{vlSymsp->TOP.t_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vudp::Vudp(const char* _vcname__)
    : Vudp(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vudp::~Vudp() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vudp___024root___eval_debug_assertions(Vudp___024root* vlSelf);
#endif  // VL_DEBUG
void Vudp___024root___eval_static(Vudp___024root* vlSelf);
void Vudp___024root___eval_initial(Vudp___024root* vlSelf);
void Vudp___024root___eval_settle(Vudp___024root* vlSelf);
void Vudp___024root___eval(Vudp___024root* vlSelf);

void Vudp::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vudp::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vudp___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vudp___024root___eval_static(&(vlSymsp->TOP));
        Vudp___024root___eval_initial(&(vlSymsp->TOP));
        Vudp___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vudp___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vudp::eventsPending() { return false; }

uint64_t Vudp::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vudp::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vudp___024root___eval_final(Vudp___024root* vlSelf);

VL_ATTR_COLD void Vudp::final() {
    Vudp___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vudp::hierName() const { return vlSymsp->name(); }
const char* Vudp::modelName() const { return "Vudp"; }
unsigned Vudp::threads() const { return 1; }
void Vudp::prepareClone() const { contextp()->prepareClone(); }
void Vudp::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vudp::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vudp___024root__trace_decl_types(VerilatedVcd* tracep);

void Vudp___024root__trace_init_top(Vudp___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vudp___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vudp___024root*>(voidSelf);
    Vudp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vudp___024root__trace_decl_types(tracep);
    Vudp___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vudp___024root__trace_register(Vudp___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vudp::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vudp::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vudp___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
