#ifndef __NAMECARD__
#define __NAMECARD__

using namespace std;

typedef struct _namecard
{
    string name;
    string phone;

    _namecard(string name, string phone);
} NameCard;

void ShowNameCardInfo(NameCard *pcard);
bool NameCompare(NameCard *pcard, string name);
void ChangePhoneNum(NameCard *pcard, string phone);

#endif