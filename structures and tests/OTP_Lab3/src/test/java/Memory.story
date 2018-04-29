Scenario: getting variables
Given an empty env
When I save variable <var>
And I get saved variable <varname>
Then I should get saved variable <result>
And saved variables numbers should be <num>

Examples:
|var                                                                  |varname           |result                         | num|
|k = 100.00 + 112.5                                                   |k                 |212.5                          |1|
|l = [{1, 2}, {2, 1}] + [{1, 2}, {2, 1}]                              |l                 |[[2.0, 4.0]  [4.0, 2.0]]       |1|
|m = det([{2, 4}, {4, 2}])                                            |m                 |-12.0                          |1|
|n = det([{1, 2}, {2, 1}] * 0.5 + [{1, 2}, {2, 1}] * 2)               |n                 |-18.75                         |1|
|karna = det([{1, 2}, {2, 1}] * 0.5 + [{1, 2}, {2, 1}] * 2)           |karna             |-18.75                         |1|

Scenario: saving variables
Given an empty env
When I save variable <var>
Then I should get output <result>
And saved variables numbers should be <num>

Examples:
|var                                                                            |result                         | num|
|k = 100.00 + 112.5                                                             |212.5                          |1|
|l = [{1, 2}, {2, 1}] + [{1, 2}, {2, 1}]                                        |[[2.0, 4.0]  [4.0, 2.0]]       |1|
|m = det([{2, 4}, {4, 2}])                                                      |-12.0                          |1|
|n = det([{1, 2}, {2, 1}] * 0.5 + [{1, 2}, {2, 1}] * 2)                         |-18.75                         |1|
|karna = det([{1, 2}, {2, 1}] * 0.5 + [{1, 2}, {2, 1}] * 2)                     |-18.75                         |1|

Scenario: getting variables from empty env
Given an empty env
When I enter invalid operation <notSetVariable>
Then I should get result <MSG>

Examples:
|notSetVariable  | MSG                             |
|N               | ERROR. Variable 'N' is undefined|
|det(A)          | ERROR. Variable 'A' is undefined|
|C * W           | ERROR. Variable 'C' is undefined|

Scenario: setting already existing variable
Given an empty env
When I save variable <var>
And I save variable <sameNameVar>
And I get saved variable <varname>
Then I should get saved variable <result>
And saved variables numbers should be <num>

Examples:
|var                                                              |sameNameVar                  |varname |result            | num|
|k = 100.00 + 112.5                                               |k = 5                        |k       |5.0               |1|
|l = [{1, 2}, {2, 1}] + [{1, 2}, {2, 1}]                          |l = 100.00 + 112.5           |l       |212.5             |1|
|m = det([{2, 4}, {4, 2}])                                        |m = [{2, 4}, {4, 2}]         |m       |[{2, 4}, {4, 2}]  |1|
|n = det([{1, 2}, {2, 1}] * 0.5 + [{1, 2}, {2, 1}] * 2)           |n = 100.00 + 112.5           |n       |212.5             |1|
|karna = det([{1, 2}, {2, 1}] * 0.5 + [{1, 2}, {2, 1}] * 2)       |karna = det([{2, 4}, {4, 2}])|karna   |-12.0             |1|
