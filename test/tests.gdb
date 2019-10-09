# Test file for Lab3_bitManip


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x00, PINB: 0x00 => PORTC: 0x00"
# Set inputs
setPINA 0x00
setPINB 0x00
# Continue for several ticks
continue 0
# Set expect values
expectPORTC 0x00
# Check pass/fail
checkResult

# Add tests below
test "PINA: 0xFF, PINB: 0xFF; => PORTC: 0x10"
setPINA 0xFF
setPINB 0xFF
continue 0
expectPORTC 0x10
checkResult
 
test "PINA: 0x01, PINB: 0x01; => PORTC: 0x02"
setPINA 0x01
setPINB 0x01
continue 0
expectPORTC 0x02
checkResult

test "PINA: 0x74 , PINB:0x22 ; => PORTC: 0x06"
setPINA 0x74 
setPINB 0x22
continue 0
expectPORTC 0x06 
checkResult

test "PINA:0xE7 , PINB:0x76 => PORTC:0x0B"
setPINA 0xE7
setPINB 0x76
continue 0
expectPORTC 0x0B
checkResult

test "PINA:0x3A , PINB:0x91 => PORTC:0x07 "
setPINA 0x3A
setPINB 0x91
continue 0
expectPORTC 0x07
checkResult

test "PINA:0x50 , PINB:0x07 => PORTC:0x05 "
setPINA 0x50
setPINB 0x07
continue 0
expectPORTC 0x05
checkResult
 
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
