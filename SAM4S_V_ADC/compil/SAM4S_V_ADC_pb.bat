echo OFF
set local_svnvalid_directory=%SVNVALID_ENV%
REM set compil_directory=%local_svnvalid_directory%\dev__SAM4S_ValidTemplate\_SAM4S_ValidTemplate\compil

REM ------- utils-----------------------------------------
set utils_dir=%local_svnvalid_directory%\___utils
set objcopy_call=%utils_dir%\at91objcopy\at91objcopy.exe
REM ------------------------------------------------------



echo *********************************** post-buid script execution log ************************************************************

REM ---) Uncomment next lines to generate a 64bits text header file, from original .bin file ---------------------(
echo    --) Post build: generating .h64 file...
IF EXIST %1.h64 (del %1.h64)
echo POST BUILD WARNING: This script uses a beta version of objcopy !!! Please check the end of the output file...
%objcopy_call% /module %1=0 /output %1.h64 /64
REM --------------------------------------------------------------------------------------------------------------(

echo *********************************** end of post-buid script execution  ********************************************************




echo ON