# calculator
Context-free grammar with the following production rules:<br>
Expression = Term | Term + Expression |  Term - Expression<br>
Term = Factor | Factor * Term | Factor / Term<br>
Factor = Float | (Expression)<br>
Float handled by stof<br>
