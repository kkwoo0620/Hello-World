#ifndef __NAMECARD_H__
#define __NAMECARD_H__

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
}

class NameCard {
private:
	char *name;
	char *company;
	char *phone;
	int position;
public:
	NameCard(const char *name, const char *company, const char *phone, int pos);
	void ShowNameCardInfo();


};

#endif