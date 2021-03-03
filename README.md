***The expression calculator***
===========================
***This project was carried out as part of the laboratory work on the discipline "Basics of building translators". The time was spent enough, but the work was not properly evaluated. During the execution of the work, no mathematical expressions similar to the parser implementation were found in the network. I publish the material in the hope that it will be useful to someone. I draw your attention to the availability of the GNU General Public License v3.0. Be good guys)).***

---
**Established rules**
* The rules for writing expressions correspond to the standard mathematical ones.
* Variables can be multi-character, and can contain uppercase and lowercase letters of the English language.
* The record of constants and variable values can have either an integer record format or a decimal point format.
* Following any two operation symbols in a row is an unacceptable situation.
* The presence of spaces does not matter.

Priority |	Symbol |	Operation
---|----|---------     
1 | () | brackets
2 | ^ | exponentiation
3 | - | unary minus
3 | + | unary plus
4 | * | multiplication
4 | / | division
5 | + | addition
5 | - | subtraction
