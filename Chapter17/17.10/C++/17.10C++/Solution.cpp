#include "Solution.h"

std::string nTab(int n)
{
	std::string indent = "";

	for (int i = 0; i < n; i++)
		indent += "\t";

	return indent;
}

std::ostream& operator<< (std::ostream & xmlStream, XMLElement& root)
{
	return outputHelper(xmlStream, root, 0);
}

std::ostream& outputHelper(std::ostream & xmlStream, XMLElement& root, int indent)
{
	if (root.m_tag == "") /*Null element*/
		return xmlStream;
	else if (root.m_hasValue) /*Value element: <tag><value></tag>*/
	{
		if (indent != 0)
			xmlStream << "\n";
		xmlStream << nTab(indent)<<"<" << root.m_tag;
		for (std::list<Attribute>::iterator it = root.m_attributes.begin(); it != root.m_attributes.end(); it++)
		{
			if (it->getTag() != "")
				xmlStream << " " << it->getTag() << "=\"" << it->getValue() << "\"";
		}

		if (root.m_value != "")
		{
			xmlStream << ">";
			xmlStream << "" << root.m_value << "";
			xmlStream << "</" << root.m_tag << ">";
		}
		else
		{
			xmlStream << "/>";
		}

	}
	else /*Nested element: indented printing*/
	{
		if (indent != 0)
			xmlStream << "\n";
		xmlStream <<nTab(indent) << "<" << root.m_tag;
		for (std::list<Attribute>::iterator it = root.m_attributes.begin(); it != root.m_attributes.end(); it++)
		{
			if (it->getTag() != "")
				xmlStream << " " << it->getTag() << "=\"" << it->getValue() << "\"";
		}
		xmlStream << ">";

		for (std::list<XMLElement*>::iterator it = root.m_children.begin(); it != root.m_children.end(); it++)
		{
			XMLElement child = *(*it);
			outputHelper(xmlStream, child, indent + 1);
		}
		xmlStream << "\n" << nTab(indent) << "</" << root.m_tag << ">";
	}
	return xmlStream;
}