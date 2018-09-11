
REM del folders
IF EXIST compil\FLASH\Obj (rd compil\FLASH\Obj /S/Q)
IF EXIST compil\FLASH\List (rd compil\FLASH\List /S/Q)
IF EXIST compil\ISRAM\Obj (rd compil\ISRAM\Obj /S/Q)
IF EXIST compil\ISRAM\List (rd compil\ISRAM\List /S/Q)
IF EXIST compil\ICE\Obj (rd compil\ICE\Obj /S/Q)
IF EXIST compil\ICE\List (rd compil\ICE\List /S/Q)
IF EXIST compil\settings (rd compil\settings /S/Q)


REM del files
IF EXIST compil\*.dep (del compil\*.dep /Q)
IF EXIST compil\*.sfr (del compil\*.sfr /Q)

REM end

