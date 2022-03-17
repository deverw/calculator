# calculator
C++ implementation to evaluate arithmetic expression with basic operations and brackets, considering 'dots before dashes'-rule.<br>
Test cases:<br>
1 + 1 &rarr; 2.0000<br>
1 + 2 + 3 &rarr; 6.0000<br>
1 + 2 * 3 &rarr; 7.0000<br>
(1 + 2) * 3 &rarr; 9.0000<br>
1 + 2 * (3 + 4 + 5 * (6 + 7)) &rarr; 145.0000<br>
<br>
Context-free grammar with the following production rules:<br>
Expression = Term | Term + Expression |  Term - Expression<br>
Term = Factor | Factor * Term | Factor / Term<br>
Factor = Float | (Expression)<br>
Float handled by stof<br>
