1. Project Files
Main.cpp: Test Driver for Solution
Input.txt: Test Input
Output.txt: Test Output
Solution.h: Header file for Solution
Solution.cpp: Implementation for Solution

2. Input Specification (TODO)
Support indented display and self-closure
<tag>
	<tag2>value<tag2/>
	<tag3>
		<tag4>value4</tag4>
		<tag5 attib1 />
	</tag3>
</tag>

3. Output Sepcification
Support indented display and self-closure
<tag>
	<tag2>value<tag2/>
	<tag3>
		<tag4>value4</tag4>
		<tag5 attib1 />
	</tag3>
</tag>

4. Solution Scope
XML display (Done)
XML reading (TODO)
solve original problem (TODO)

5. Solution Comment
Main: read input file, pass valid xml string delimited by # to String2XML
Driver Class: String2XML read the string and create XMLelement (+parse)
Helper Class: XMLElement, Attribute



