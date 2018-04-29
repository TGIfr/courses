Scenario: without saving
Given an empty env
When I enter expression with no variables without saving  <expr>
Then I should get output <result>

Examples:
|expr                                                             |result                              |
|120 + 112.5                                                      |232.5                               |
|det([{2, 4}, {2, 2}])                                            |-4.0                                |
| 5 * [{2, 4}, {2, 2}]                                            | [10.0, 20.0] [10.0, 10.0]          |
| [{2, 4}, {2, 2}, {2, 2}]                                        | [2.0, 4.0] [2.0, 2.0] [2.0, 2.0]   |
| [5]                                                             | [5.0]                                |
| [5,5,9,9]                                                       | [5.0,5.0,9.0,9.0]                          |

Scenario: expression without saving arr
Given an empty env
When I enter matrix [{1, 2}, {2, 1}] + [{1, 2}, {2, 1}]
Then I should get output
[2.0, 4.0]
[4.0, 2.0]




Scenario: using saved variables
Given an empty env
When I save variable <A>
And I save variable <B>
And I enter expression with saved variables A and B  with no saving <expr>
Then I should get output <result>

Examples:
|A                        |B                     |expr                  |result                       |
|A = 10.00                |B = -25               |A + B                 |-15.0                        |
|A = 10.00  + 5           |B = -25               |A + B                 |-10.0                        |
|A = [{1, 2}, {2, 1}]     |B = [{6, 7}, {2, 5}]  |A + B                 |[[7.0, 9.0]  [4.0, 6.0]]     |
|A = [{1, 2}, {2, 1}]     |B = 2                 |A * B                 |[[2.0, 4.0]  [4.0, 2.0]]     |


Scenario: using saved variables and saving them
Given an empty env
When I save variable A <input1>
And I save variable  B <input2>
And I enter expression with saved variables A and B and save it in C  <input3>
And I get saved variable <var>
Then I should get output <result>

Examples:
|input1                   |input2                |input3           |var   |result                       |
|A = 10.00                |B = -25               |C = A + B        |C        |-15.0                        |
|A = [{1, 2}, {2, 1}]     |B = [{6, 7}, {2, 5}]  |C = A + B        |C        |[[7.0, 9.0]  [4.0, 6.0]]     |
|A = [{1, 2}, {2, 1}]     |B = [{6, 7}, {2, 5}]  |C = det(A + B)   |C        |6.0                          |



Scenario: invalid operations form
Given an empty env
When I enter invalid operation <input>
Then I should get err <value>

Examples:
|input                           | value|
|A = 5 +                         |ERROR. Invalid operation form. It's a binary operation|
| 5 *                            |ERROR. Invalid operation form. It's a binary operation|

Scenario: variables names case
Given an empty env
When I save variable <input1>
And I get not saved var <var>
Then I should get err <value>

Examples:
|input1                   |var                         |value                              |
|A = 10.00                |a                           |ERROR. Variable 'a' is undefined   |
|b = [{1, 2}, {2, 1}]     |B                           |ERROR. Variable 'B' is undefined   |
|cab = [{1, 2}, {2, 1}]   |cAB                         |ERROR. Variable 'cAB' is undefined |

Scenario: matrix mult is not available
Given an empty env
When I enter not available operation  <input>
Then I should get an error message <message>

Examples:
|input                                                            |message                                          |
|[{2, 4}, {2, 2}]  * [{2, 4}, {2, 2}]                             |Multiplication of matrix is not available        |
|det(5.5)                                  |Cannot calculate determinant of not a matrix variable|


