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
java Gen 10 10 >Test00\stairs.inp
java Gen 50 100 >Test01\stairs.inp
java Gen 100 500 >Test02\stairs.inp
java Gen 200 1000 >Test03\stairs.inp
java Gen 300 10000 >Test04\stairs.inp
java Gen 500 200000 >Test05\stairs.inp
java Gen 900 500000 >Test06\stairs.inp
java Gen 1000 1000000 >Test07\stairs.inp
java Gen 2000 20000000 >Test08\stairs.inp
java Gen 5000 1000000000 >Test09\stairs.inp
