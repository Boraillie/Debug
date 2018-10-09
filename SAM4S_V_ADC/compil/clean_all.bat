
REM del folders
IF EXIST FLASH (rd FLASH /S/Q)
IF EXIST ICE (rd ICE /S/Q)
IF EXIST ISRAM (rd ISRAM /S/Q)
IF EXIST settings (rd settings /S/Q)

REM del files
IF EXIST *.dep (del *.dep /Q)

REM end

