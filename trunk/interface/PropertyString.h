// PropertyString.h

#if !defined PropertyString_HEADER
#define PropertyString_HEADER

#include "Property.h"

class PropertyString:public Property{
private:
	wxString m_title;

public:
	wxString m_initial_value;
	HeeksObj* m_object;
	void(*m_callbackfunc)(const wxChar*, HeeksObj*);

	PropertyString(const wxChar* t, const wxChar* v, HeeksObj* object, void(*callbackfunc)(const wxChar*, HeeksObj*) = NULL);

	// Property's virtual functions
	int get_property_type(){return StringPropertyType;}
	bool property_editable()const{return m_callbackfunc != NULL;}
	Property *MakeACopy(void)const;
	void CallSetFunction()const{ if(m_callbackfunc)(*m_callbackfunc)(m_initial_value.c_str(), m_object);}

	// HeeksObj's virtual functions
	const wxChar* GetShortString(void)const;
};

#endif
