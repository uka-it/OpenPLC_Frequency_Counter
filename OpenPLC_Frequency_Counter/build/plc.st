TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM FrequencyCounter
  VAR
    Frequency_In : BOOL;
    Frequency_Value : UINT;
  END_VAR
  VAR
    Clock : BOOL;
    TON0 : TON;
    CTU0 : CTU;
    F_Aux_00 : INT;
    F_Aux_01 : INT;
    F_Aux_02 : INT;
    F_Aux_03 : INT;
    F_SUM : INT;
    F_AVERAGE : REAL;
    F_TRIG0 : F_TRIG;
    R_TRIG0 : R_TRIG;
    CTU1 : CTU;
    F_TRIG1 : F_TRIG;
    R_TRIG1 : R_TRIG;
    _TMP_MUL57_OUT : REAL;
    _TMP_REAL_TO_UINT56_OUT : UINT;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    _TMP_MOVE16_ENO : BOOL;
    _TMP_MOVE16_OUT : INT;
    _TMP_MOVE44_ENO : BOOL;
    _TMP_MOVE44_OUT : INT;
    _TMP_ADD66_OUT : INT;
    _TMP_INT_TO_REAL73_OUT : REAL;
    _TMP_MUL72_OUT : REAL;
  END_VAR

  TON0(IN := NOT(Clock), PT := T#200ms);
  Clock := TON0.Q;
  _TMP_MUL57_OUT := MUL(F_AVERAGE, 5.2632);
  _TMP_REAL_TO_UINT56_OUT := REAL_TO_UINT(_TMP_MUL57_OUT);
  Frequency_Value := _TMP_REAL_TO_UINT56_OUT;
  R_TRIG0(CLK := Frequency_In);
  R_TRIG2(CLK := R_TRIG0.Q);
  F_TRIG0(CLK := Clock);
  CTU0(CU := R_TRIG2.Q, R := F_TRIG0.Q, PV := 2000);
  F_Aux_00 := CTU0.CV;
  R_TRIG1(CLK := Frequency_In);
  R_TRIG3(CLK := R_TRIG1.Q);
  F_TRIG1(CLK := Clock);
  CTU1(CU := R_TRIG3.Q, R := F_TRIG1.Q, PV := 2000);
  F_Aux_01 := CTU1.CV;
  _TMP_MOVE16_OUT := MOVE(EN := Clock, IN := F_Aux_00, ENO => _TMP_MOVE16_ENO);
  IF _TMP_MOVE16_ENO THEN
      F_Aux_02 := _TMP_MOVE16_OUT;
  END_IF;
  _TMP_MOVE44_OUT := MOVE(EN := Clock, IN := F_Aux_01, ENO => _TMP_MOVE44_ENO);
  IF _TMP_MOVE44_ENO THEN
      F_Aux_03 := _TMP_MOVE44_OUT;
  END_IF;
  _TMP_ADD66_OUT := ADD(F_Aux_02, F_Aux_03);
  F_SUM := _TMP_ADD66_OUT;
  _TMP_INT_TO_REAL73_OUT := INT_TO_REAL(F_SUM);
  _TMP_MUL72_OUT := MUL(_TMP_INT_TO_REAL73_OUT, 0.5);
  F_AVERAGE := _TMP_MUL72_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#0.5ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : FrequencyCounter;
  END_RESOURCE
END_CONFIGURATION
