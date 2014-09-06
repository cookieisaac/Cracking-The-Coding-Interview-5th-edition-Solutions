#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <string>
#include <list>

class XMLElement;
class Attribute;

class Attribute
{
public:
	Attribute(std::string tag = "", std::string value = "") :m_tag(tag), m_value(value){}
	std::string getTag(){ return m_tag; }
	std::string getValue() { return m_value; }
	void setTag(std::string tag){ m_tag = tag; }
	void setValue(std::string value){ m_value = value; }

private:
	std::string m_tag;
	std::string m_value;
};

std::ostream& operator<< (std::ostream &, XMLElement&);
std::string nTab(int n);
std::ostream& outputHelper(std::ostream &, XMLElement&, int);

class XMLElement
{
public:
	XMLElement(std::string tag = "", std::string value = "") :m_tag(tag), m_value(value) { if (m_value != "") m_hasValue = true; else m_hasValue = false; }

	void setTag(std::string tag){ m_tag = tag; }
	void setValue(std::string value){ m_value = value; if (m_value != "") m_hasValue = true; else m_hasValue = false; }
	std::string getTag(){ return m_tag; }
	std::string getValue(){ return m_value; }

	void addAttribute(Attribute attribute){ m_attributes.push_back(attribute); }
	void addChild(XMLElement* child){ m_children.push_back(child); }
	
	friend std::ostream& operator<< (std::ostream &, XMLElement&);
	friend std::ostream& outputHelper(std::ostream &, XMLElement&, int);

private:
	std::string m_tag;
	std::string m_value;
	std::list <Attribute> m_attributes;
	std::list <XMLElement*> m_children;
	bool m_hasValue;
};

class String2XMLParser
{
public:
	String2XMLParser(std::string str) :m_string(str){}
	void parseString();

	XMLElement getXMLObject(){ return m_xml; };

private:
	std::string m_string;
	XMLElement m_xml;
};

#endif