# calculator
C++ implementation to evaluate arithmetic expression with basic operations and brackets, considering <q>dots before dashes</q>-rule.<br>
Interpretation of input string using context-free grammar with the following rules:<br>
&lt;Expression&gt;&ensp; = &ensp;&lt;Product&gt;&ensp; | &ensp;&lt;Product&gt; <code>+</code> &lt;Expression&gt;&ensp; |  &ensp;&lt;Product&gt; <code>-</code> &lt;Expression&gt;<br>
&lt;Product&gt;&ensp; = &ensp;&lt;Value&gt;&ensp; | &ensp;&lt;Value&gt; <code>*</code> &lt;Product&gt;&ensp; | &ensp;&lt;Value&gt; <code>/</code> &lt;Product&gt;<br>
&lt;Value&gt;&ensp; = &ensp;<code>float</code>&ensp; | &ensp;<code>(</code>&lt;Expression&gt;<code>)</code><br>

Start:<pre><code>
git clone https://github.com/deverw/calculator
cd calculator
make
./calculator
</code></pre>

Test cases:<pre><code>
1+1 &rarr; 2
1+2+3 &rarr; 6
1+2&#42;3 &rarr; 7
(1+2)&#42;3 &rarr; 9
1+2&#42;(3+4+5&#42;(6+7)) &rarr; 145
2&#42;(3+4&#42;(5+6&#42;(7+8&#42;(9+10.123456789)))) &rarr; 7725.407227
2/(4.5-2&#42;(0.3+1.091))+3.1415927 &rarr; 4.305737
</code></pre><br>
