    ; Bootcode for CORTEX-A5 and A7 ?

;    AREA    PERFMON, CODE
        MODULE  ?perform


        SECTION .perform:CODE:NOROOT(2)


    ; -------------------
    ; Performance monitor
    ; -------------------

    ; Events that can be detected by the cortex-a8/a9 performance monitor

eventSoftware            EQU 0x00
eventICacheMiss          EQU 0x01
eventInstrTLBMiss        EQU 0x02
eventDCacheMiss          EQU 0x03
eventDCacheAccess        EQU 0x04
eventDataTLBMiss         EQU 0x05
eventDataRead            EQU 0x06
eventDataWrite           EQU 0x07
eventInstruction         EQU 0x08
eventExceptionTaken      EQU 0x09
eventExceptionReturn     EQU 0x0A
eventContextID           EQU 0x0B
eventPCSoftwareChange    EQU 0x0C
eventBranchInstruction   EQU 0x0D
eventReturn              EQU 0x0E
eventUnalignedAccess     EQU 0x0F
eventBranchNotPredict    EQU 0x10
eventBranchTaken         EQU 0x12


; A9- Jazelle 
eventBytecodExecuted     EQU 0x40 	
eventSwBytecodeExecuted	 EQU 0x41 	
eventJazBackBrExecuted	 EQU 0x42 	

; A9 additional events
eventICacheStalls 		 EQU 0x60 	
eventDCacheStalls		 EQU 0x61 	
eventTLBMissStalls		 EQU 0x62	
eventSTREXpassed		 EQU 0x63 	
eventSTREXfailed		 EQU 0x64	
eventDataEvict			 EQU 0x65	
eventInstrExecuted		 EQU 0x68	
eventInstrDecoded		 EQU 0x6E	



DivideCounter            EQU 0x8
PMN_Scale                DCD 1
ResetAndEnable           EQU 0x07

Metric0                  EQU eventInstruction
PMN_Metric0              DCB  "Instruction",0

Metric1                  EQU eventInstruction
PMN_Metric1              DCB  "Instruction",0

Metric2                  EQU eventDCacheMiss
PMN_Metric2              DCB  "DCacheMiss",0

Metric3                  EQU eventDCacheAccess
PMN_Metric3              DCB  "DCacheAccess",0

Metric4                  EQU 0
PMN_Metric4              DCB  "Not used",0

Metric5                  EQU 0
PMN_Metric5              DCB  "Not used",0



    EXPORT PMN_Reset
    EXPORT PMN_Stop
    EXPORT PMN_Read_Overflow
    EXPORT PMN_Read_Cycles
    EXPORT PMN_Read_Reg0
    EXPORT PMN_Read_Reg1
    EXPORT PMN_Read_Reg2
    EXPORT PMN_Read_Reg3
    EXPORT PMN_Read_Reg4
    EXPORT PMN_Read_Reg5    
    EXPORT PMN_Metric0
    EXPORT PMN_Metric1
    EXPORT PMN_Metric2
    EXPORT PMN_Metric3
    EXPORT PMN_Metric4
    EXPORT PMN_Metric5    
    EXPORT PMN_Scale

    ALIGNRAM 5, 0

PMN_Reset
    MRC     p15, 0, r1, c9, c12, 0
    BIC     r1, r1, #0xF
    MCR     p15, 0, r1, c9, c12, 0   ; Disable all counters

;    MOV     r2, #0
;    MCR     p15, 0, r2, c9, c12, 5   ; Select counter 0
;    MOV     r3, #Metric0
;    MCR     p15, 0, r3, c9, c13, 1   ; Write Metric

;    MOV     r2, #1
;    MCR     p15, 0, r2, c9, c12, 5   ; Select counter 1
;    MOV     r3, #Metric1
;    MCR     p15, 0, r3, c9, c13, 1   ; Write Metric

;    MOV     r2, #2
;    MCR     p15, 0, r2, c9, c12, 5   ; Select counter 2
;    MOV     r3, #Metric2
;    MCR     p15, 0, r3, c9, c13, 1   ; Write Metric

;    MOV     r2, #3
;    MCR     p15, 0, r2, c9, c12, 5   ; Select counter 3
;    MOV     r3, #Metric3
;    MCR     p15, 0, r3, c9, c13, 1   ; Write Metric

;	 MOV     r2, #4
;    MCR     p15, 0, r2, c9, c12, 5   ; Select counter 4
;    MOV     r3, #Metric4
;    MCR     p15, 0, r3, c9, c13, 1   ; Write Metric
	
;	 MOV     r2, #5
;    MCR     p15, 0, r2, c9, c12, 5   ; Select counter 5
;    MOV     r3, #Metric5
;    MCR     p15, 0, r3, c9, c13, 1   ; Write Metric

    MOV     r0, #0x8000003F
    MCR     p15, 0, r0, c9, c14, 2   ; Disable overflow interrupts
    MCR     p15, 0, r0, c9, c12, 3   ; Clear overflow flags
    MCR     p15, 0, r0, c9, c12, 1   ; Enable counters

    ORR     r1, r1, #ResetAndEnable
    MCR     p15, 0, r1, c9, c12, 0   ; Reset and Master Enable counters
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Stop
    MOV     r0, #0x8000003F
    MCR     p15, 0, r0, c9, c12, 2   ; Disable counters
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Read_Overflow
    MRC     p15, 0, r0, c9, c12, 3   ; Read overflow register
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Read_Cycles
    MRC     p15, 0, r0, c9, c13, 0   ; Read CCNT Register
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Read_Reg0
    MOV     r1, #0
    MCR     p15, 0, r1, c9, c12, 5 ; Select counter 0
    MRC     p15, 0, r0, c9, c13, 2 ; Read value
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Read_Reg1
    MOV     r1, #1
    MCR     p15, 0, r1, c9, c12, 5 ; Select counter 1
    MRC     p15, 0, r0, c9, c13, 2 ; Read value
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Read_Reg2
    MOV     r1, #2
    MCR     p15, 0, r1, c9, c12, 5 ; Select counter 2
    MRC     p15, 0, r0, c9, c13, 2 ; Read value
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Read_Reg3
    MOV     r1, #3
    MCR     p15, 0, r1, c9, c12, 5 ; Select counter 3
    MRC     p15, 0, r0, c9, c13, 2 ; Read value
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Read_Reg4
    MOV     r1, #4
    MCR     p15, 0, r1, c9, c12, 5 ; Select counter 4
    MRC     p15, 0, r0, c9, c13, 2 ; Read value
    BX      lr

    ; ------------------------------------------------------------------------

PMN_Read_Reg5
    MOV     r1, #5
    MCR     p15, 0, r1, c9, c12, 5 ; Select counter 5
    MRC     p15, 0, r0, c9, c13, 2 ; Read value
    BX      lr

    ; ------------------------------------------------------------------------


;==================================================================


        END                                 ; mark the end of this file
