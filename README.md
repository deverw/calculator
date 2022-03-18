# calculator
C++ implementation to evaluate arithmetic expression with basic operations and brackets, considering "dots before dashes"-rule.<br>
Test cases:<br><pre><code>
1+1 &rarr; 2
1+2+3 &rarr; 6
1+2&#42;3 &rarr; 7
(1+2)&#42;3 &rarr; 9
1+2&#42;(3+4+5&#42;(6+7)) &rarr; 145
2&#42;(3+4&#42;(5+6&#42;(7+8&#42;(9+10.123456789)))) &rarr; 7725.407227
2/(4.5-2&#42;(0.3+1.091))+3.1415927 &rarr; 4.305737
</pre></code><br>
Context-free grammar with the following production rules:<br>
Expression = Product | Product + Expression |  Product - Expression<br>
Product = Value | Value * Product | Value / Product<br>
Value = float | (Expression)<br>
