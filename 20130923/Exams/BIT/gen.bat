@echo off
javac *.java
mkdir Test00
mkdir Test01
mkdir Test02
mkdir Test03
mkdir Test04
mkdir Test05
mkdir Test06
mkdir Test07
mkdir Test08
mkdir Test09
echo Test00
java GenTest 3 5 >Test00\BIT.INP
echo Test01
java GenTest 5 10 >Test01\BIT.INP
echo Test02
java GenTest 6 10 >Test02\BIT.INP
echo Test03
java GenTest 10 8 >Test03\BIT.INP
echo Test04
java GenTest 15 14 >Test04\BIT.INP
echo Test05
java GenTest 30 28 >Test05\BIT.INP
echo Test06
java GenTest 50 60 >Test06\BIT.INP
echo Test07
java GenTest 100 120 >Test07\BIT.INP
echo Test08
java GenTest 150 140 >Test08\BIT.INP
echo Test09
java GenTest 200 256 >Test09\BIT.INP
echo Test00
java BIT <Test00\BIT.INP >Test00\BIT.OUT 
echo Test01
java BIT <Test01\BIT.INP >Test01\BIT.OUT 
echo Test02
java BIT <Test02\BIT.INP >Test02\BIT.OUT 
echo Test03
java BIT <Test03\BIT.INP >Test03\BIT.OUT 
echo Test04
java BIT <Test04\BIT.INP >Test04\BIT.OUT 
echo Test05
java BIT <Test05\BIT.INP >Test05\BIT.OUT 
echo Test06
java BIT <Test06\BIT.INP >Test06\BIT.OUT 
echo Test07
java BIT <Test07\BIT.INP >Test07\BIT.OUT 
echo Test08
java BIT <Test08\BIT.INP >Test08\BIT.OUT 
echo Test09
java BIT <Test09\BIT.INP >Test09\BIT.OUT
