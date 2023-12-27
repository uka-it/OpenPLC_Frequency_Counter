void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





static inline INT __FREQUENCYCOUNTER_MOVE__INT__INT1(BOOL EN,
  INT IN,
  FREQUENCYCOUNTER *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE16_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE16_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __FREQUENCYCOUNTER_MOVE__INT__INT2(BOOL EN,
  INT IN,
  FREQUENCYCOUNTER *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE44_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE44_ENO,,__TMP_ENO);
  return __res;
}

void FREQUENCYCOUNTER_init__(FREQUENCYCOUNTER *data__, BOOL retain) {
  __INIT_VAR(data__->FREQUENCY_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FREQUENCY_VALUE,0,retain)
  __INIT_VAR(data__->CLOCK,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->F_AUX_00,0,retain)
  __INIT_VAR(data__->F_AUX_01,0,retain)
  __INIT_VAR(data__->F_AUX_02,0,retain)
  __INIT_VAR(data__->F_AUX_03,0,retain)
  __INIT_VAR(data__->F_SUM,0,retain)
  __INIT_VAR(data__->F_AVERAGE,0,retain)
  F_TRIG_init__(&data__->F_TRIG0,retain);
  R_TRIG_init__(&data__->R_TRIG0,retain);
  CTU_init__(&data__->CTU1,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->_TMP_MUL57_OUT,0,retain)
  __INIT_VAR(data__->_TMP_REAL_TO_UINT56_OUT,0,retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  __INIT_VAR(data__->_TMP_MOVE16_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE16_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE44_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE44_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD66_OUT,0,retain)
  __INIT_VAR(data__->_TMP_INT_TO_REAL73_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL72_OUT,0,retain)
}

// Code part
void FREQUENCYCOUNTER_body__(FREQUENCYCOUNTER *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->CLOCK,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 200, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,CLOCK,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->,_TMP_MUL57_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->F_AVERAGE,),
    (REAL)5.2632));
  __SET_VAR(data__->,_TMP_REAL_TO_UINT56_OUT,,REAL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_MUL57_OUT,)));
  __SET_VAR(data__->,FREQUENCY_VALUE,,__GET_VAR(data__->_TMP_REAL_TO_UINT56_OUT,));
  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->FREQUENCY_IN,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->R_TRIG0.Q,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->F_TRIG0.,CLK,,__GET_VAR(data__->CLOCK,));
  F_TRIG_body__(&data__->F_TRIG0);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->F_TRIG0.Q,));
  __SET_VAR(data__->CTU0.,PV,,2000);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,F_AUX_00,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->FREQUENCY_IN,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->R_TRIG1.Q,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->CLOCK,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->F_TRIG1.Q,));
  __SET_VAR(data__->CTU1.,PV,,2000);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,F_AUX_01,,__GET_VAR(data__->CTU1.CV,));
  __SET_VAR(data__->,_TMP_MOVE16_OUT,,__FREQUENCYCOUNTER_MOVE__INT__INT1(
    (BOOL)__GET_VAR(data__->CLOCK,),
    (INT)__GET_VAR(data__->F_AUX_00,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE16_ENO,)) {
    __SET_VAR(data__->,F_AUX_02,,__GET_VAR(data__->_TMP_MOVE16_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE44_OUT,,__FREQUENCYCOUNTER_MOVE__INT__INT2(
    (BOOL)__GET_VAR(data__->CLOCK,),
    (INT)__GET_VAR(data__->F_AUX_01,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE44_ENO,)) {
    __SET_VAR(data__->,F_AUX_03,,__GET_VAR(data__->_TMP_MOVE44_OUT,));
  };
  __SET_VAR(data__->,_TMP_ADD66_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->F_AUX_02,),
    (INT)__GET_VAR(data__->F_AUX_03,)));
  __SET_VAR(data__->,F_SUM,,__GET_VAR(data__->_TMP_ADD66_OUT,));
  __SET_VAR(data__->,_TMP_INT_TO_REAL73_OUT,,INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->F_SUM,)));
  __SET_VAR(data__->,_TMP_MUL72_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_INT_TO_REAL73_OUT,),
    (REAL)0.5));
  __SET_VAR(data__->,F_AVERAGE,,__GET_VAR(data__->_TMP_MUL72_OUT,));

  goto __end;

__end:
  return;
} // FREQUENCYCOUNTER_body__() 





